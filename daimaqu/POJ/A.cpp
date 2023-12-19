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

int a[N],b[N];

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

    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

    push_up(u);
    
}

void modify(int u,int k,int x)
{
    if (tr[u].l == tr[u].r)
    {
        tr[u].sum = 0;
        tr[u].value = x;
        return ;
    }
    if (k < tr[u << 1].sum)
    	modify(u << 1, k, x);
    else
    {
        k -= tr[u << 1].sum;
        modify(u << 1 | 1, k, x);
    }
    push_up(u);
}

void query(int u)
{
    if(tr[u].l==tr[u].r)
    {
        cout<<tr[u].value<<' ';
        return ;
    }
    query(u<<1);
    query(u<<1|1);
    
}
void solve()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
          cin>>a[i]>>b[i];
        }

        build(1,1,n);

        for(int i=n;i>=1;i--)
        {
            modify(1,a[i],b[i]);
        }

        query(1);
        cout<<endl;
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