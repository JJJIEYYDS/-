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
const int N=2e5+10,INF=0x3f3f3f3f,mod=998244353;

ll n,m,k,q;
vector<vector<int>> e(N);
ll s[N];
ll p[N];

int dfs(int u,int f)
{
    p[u]=f;
    int num=1;
    for(auto x:e[u])
    {
        if(x!=f)
        {
            int s=dfs(x,u);
            num+=s;
        }
    }
    s[u]=num;
    return num;
}
void solve()
{
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(1,-1);

    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll t1=0,t2=0,t3=0;
        for(auto x:e[i])
        {
            if(x!=p[i]){
                t3+=t2*s[x];
                t2+=t1*s[x];
                t1+=s[x];
            }
        }
        if(n-s[i]>0)
        {
            t3+=t2*(n-s[i]);
        }
        ans+=t3;
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