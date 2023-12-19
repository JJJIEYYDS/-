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
const int N=1e6+10,INF=0x3f3f3f3f;

int n,m,k;
int p[N],pre[N];
ll cnt;
vector<int> te;

int find(int x)
{
    if(x!=p[x]) 
    {
        p[x]=find(p[x]);
    }
    return p[x];
}

void unite(int u,int v)
{
    te.emplace_back(u);
    te.emplace_back(v);

    int px=find(u);
    int py=find(v);
    if(px==py) return ;
    cnt--;
    p[px]=py;
}

void solve()
{
    cin>>n>>m>>k;
    vector<vector<PLL>> v(N+1);
    
    for(int i=1;i<=n;i++) p[i]=i;

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        for(int j=1;j*j<=c;j++)
        {
            if(c%j==0)
            {
                v[j].push_back({a,b});
                if(c/j!=j) v[c/j].push_back({a,b});
            }
        }
    }
    
    while(k--)
    {
        cnt=n;
        int x;
        cin>>x;
        for(auto [u,v]:v[x])
        {
            unite(u,v);
        }
        cout<<cnt-1<<endl;

        for(auto x:te)
        {
            p[x]=x;
        }
        te.clear();
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