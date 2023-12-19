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
const int N=1e4+10,INF=0x3f3f3f3f,mod=998244353;

ll n,m,k;
ll a[N];
bool st[N];

ll lowbit(ll x)
{
    return x&(-x);  
}
ll ans=0;

void dfs(int u,ll x)
{
    ll cnt=0,t=x;

    while(t)
    {
        t-=lowbit(t);
        cnt++;
    }
    if(cnt==k) ans++;
    
    for(int i=u+1;i<=n;i++)
    {
        ll t1=x;
        if(!st[i])
        {
            st[i]=true;
            t1&=a[i];
            dfs(i,t1);
            st[i]=false;
        }
    }
}
void solve()
{
    cin>>n>>k;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i,a[i]);
    }
    cout<<ans<<endl;

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