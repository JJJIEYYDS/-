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
const int N=1e6+10,INF=0x3f3f3f3f,mod=998244353;

int n,m,k;

ll ans[N];
vector<vector<int>> v(N);

void dfs(int u)
{
    ll res=0;
    for(auto x:v[u])
    {
        res+=v[x].size();
    }
    ans[u]=res;
}

void solve()
{
    cin>>n>>m;
    
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].emplace_back(b);
    }

    for(int i=1;i<=n;i++)
    {
        dfs(i);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
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