#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k,p;

ll a[N];

struct node
{
    ll l,r;
    ll lazy1,lazy2,sum;
}tr[N*4];

void push_up(int u)
{
    tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%p;
}

void push_down(int u)
{
    if(tr[u].l==tr[u].r)
    {
        tr[u].lazy1=0;
        tr[u].lazy2=1;
        return ;
    } 

    tr[u<<1].sum=((tr[u<<1].r-tr[u<<1].l+1)*tr[u].lazy1+tr[u<<1].sum*tr[u].lazy2)%p;
    tr[u<<1|1].sum=((tr[u<<1|1].r-tr[u<<1|1].l+1)*tr[u].lazy1+tr[u<<1|1].sum*tr[u].lazy2)%p;

    tr[u<<1].lazy1=(tr[u<<1].lazy1*tr[u].lazy2+tr[u].lazy1)%p;
    tr[u<<1|1].lazy1=(tr[u<<1|1].lazy1*tr[u].lazy2+tr[u].lazy1)%p;
    tr[u<<1].lazy2=(tr[u].lazy2*tr[u<<1].lazy2)%p;
    tr[u<<1|1].lazy2=(tr[u].lazy2*tr[u<<1|1].lazy2)%p;

    tr[u].lazy1=0;
    tr[u].lazy2=1;

}
void build(int u,int l,int r)
{
    tr[u].l=l;
    tr[u].r=r;
    tr[u].lazy1=0;
    tr[u].lazy2=1;
    tr[u].sum=0;

    if(tr[u].l==tr[u].r)
    {
        tr[u].sum=a[l]%p;
        return ;
    }

    int mid=(l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

    push_up(u);
    
}

void modify2(int u,int l,int r ,int k)
{
    if(tr[u].r<=r&&tr[u].l>=l)
    {
        tr[u].lazy1=(tr[u].lazy1*k)%p;
        tr[u].sum=(tr[u].sum*k)%p;
        tr[u].lazy2=(tr[u].lazy2*k)%p;
        return ;
    }

    push_down(u);

    int mid=(tr[u].l+tr[u].r)>>1;
    
    if(l<=mid) modify2(u<<1,l,r,k);
    if(r>mid) modify2(u<<1|1,l,r,k);
    
    
    push_up(u);


}
void modify1(int u,int l,int r,int k)
{
    if(tr[u].r<=r&&tr[u].l>=l)
    {
        tr[u].sum=(tr[u].sum+(tr[u].r-tr[u].l+1)*k)%p;
        tr[u].lazy1=(k+tr[u].lazy1)%p;
        return ;
    }

    push_down(u);

    int mid=(tr[u].l+tr[u].r)>>1;

    if(l<=mid) modify1(u<<1,l,r,k);
    if(r>mid) modify1(u<<1|1,l,r,k);

    push_up(u);

}

ll query(int u,int l,int r)
{
   if(tr[u].l>=l&&tr[u].r<=r)
   {
        return tr[u].sum%p;
   }

   push_down(u);
   int mid=(tr[u].l+tr[u].r)>>1;

   ll sum=0;
   if(r>mid) sum=(sum+query(u<<1|1,l,r));
   if(l<=mid) sum=(sum+query(u<<1,l,r));
   return sum;

}
void solve()
{
    cin>>n>>m>>p;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    build(1,1,n);
    while(m--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int b,c,d;
            cin>>b>>c>>d;
            modify2(1,b,c,d);

        }
        else if(x==2)
        {
            int b,c,d;
            cin>>b>>c>>d;
            modify1(1,b,c,d);
        }
        else 
        {
            int l,r;
            cin>>l>>r;
            cout<<query(1,l,r)%p<<endl;
        }
    }

    


}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;

    while(t--)
      solve();

    system("pause");
    return 0;
}