#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cmath>

using namespace std;

typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;
typedef long long ll;
const int N=2e5+10,INF=0x3f3f3f3f;

int n,m,k;

struct node
{
    ll l,r,sum,lazy;

}tr[N<<2];

void push_up(ll u)
{
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void push_down(ll u)
{
    if(tr[u].lazy)
    {
        tr[u<<1].sum+=tr[u].lazy*(tr[u<<1].r-tr[u<<1].l+1);
        tr[u<<1|1].sum+=tr[u].lazy*(tr[u<<1|1].r-tr[u<<1|1].l+1);
        tr[u<<1].lazy+=tr[u].lazy;
        tr[u<<1|1].lazy+=tr[u].lazy;
        tr[u].lazy=0;
    }
}
void build(ll u,ll l,ll r)
{
    if(l==r)
    {
        tr[u].l=tr[u].r;
        return ;
    }
    tr[u].sum=0;
    tr[u].l=l;
    tr[u].r=r;
    tr[u].lazy=0;

    ll mid=(l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}

void change(ll u,ll l,ll r,ll w)
{
    if(tr[u].l>=l&&tr[u].r<=r)
    {
        tr[u].sum+=(tr[u].r-tr[u].l+1)*w;
        tr[u].lazy+=w;
        return ;
    }

    push_down(u);

    ll mid =(tr[u].l+tr[u].r)>>1;
    if(l<=mid)
    {
        change(u<<1,l,mid,w);
    } 
    if(r>mid)
    {
        change(u<<1|1,mid+1,r,w);
    }
    push_up(u);
}

ll ask(ll u,ll l,ll r)
{
    ll ans=0;
    if(tr[u].l>=l&&tr[u].r<=r)
    {
        return tr[u].sum;
    }
    push_down(u);
    ll mid=(tr[u].l+tr[u].r)>>1;
    if(l<=mid)
    {
        ans+=ask(u<<1,l,mid);
    }
    if(r>mid)
    {
        ans+=ask(u<<1|1,mid+1,r);
    }
    return ans;
}

void solve()
{
    cin>>n>>m;
    build(1,1,n);

    while(m--)
    {
        int x;

        cin>>x;
        ll a,b,c;
        if(x==0)
        {
            cin>>a>>b>>c;
            change(1,a,b,c);
        }
        else 
        {
            cin>>a>>b;
            cout<<ask(1,a,b)%998244353<<endl;
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