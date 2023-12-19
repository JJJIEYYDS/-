#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=2e5+10,INF=0x3f3f3f3f;

int n,m,k;

vector<pair<int,int> > a;

struct node
{
    int l,r;
    int sum,value;
}tr[N*4];

void push_up(int u)
{
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void build(int u,int l,int r)
{
    tr[u].l=l;
    tr[u].r=r;

    if(tr[u].l==tr[u].r)
    {
        tr[u].sum=1;
        return ;
    }

    int mid=(l+r)>>1;
    tr[u].sum=0;
    tr[u].value=0;

    build(u<<1,r,mid);
    build(u<<1|1,mid+1,l);

    push_up(u);
    
}

void modify(int u,int k,int x)
{
    if(k>=tr[u<<1].sum)
    {
        k-=tr[u].sum;

        modify(u<<1,k,x);
        if(tr[u].sum==k&&tr[u].r==tr[u].l)
        {
            tr[u].sum=0;
        }
        push_up(u);
    }
    else 
    {
        modify(u<<1|1,k,x);

        if(tr[u].sum==k&&tr[u].r==tr[u].l)
        {
            tr[u].sum=0;
        }

        push_up(u);
    }
}
void solve()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
          int x,y;
          cin>>x>>y;
          a.push_back({x,y});
        }

        build(1,1,n);

        for(int i=a.size()-1;i>=0;i--)
        {
            int k=a[i].first,x=a[i].second;

            modify(1,k-1,x);
        }

        for(int i=1;i<=n;i++)
        {
            cout<<tr[i].sum<<endl;
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