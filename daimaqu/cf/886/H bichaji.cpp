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
//在每条边中记录额外的信息的并查集就是带权并查集。

ll n,m,k;
ll p[N],d[N];

ll find(ll x)
{
    if(x!=p[x])
    {
        ll t = p[x];
        p[x]=find(p[x]);
        d[x]+=d[t];
    }
    return p[x];
}

void solve()
{
    cin>>n>>m;

    memset(d,0,sizeof d);
    memset(p,0,sizeof p);

    bool flag = false;

    for(int i=1;i<=n;i++) p[i]=i;

    for(int i=1;i<=m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll px=find(a), py=find(b);
        if(px!=py)
        {
            p[px]=py;
            d[px]=c+d[b]-d[a];
        }
        else 
        {
            if(d[a]-d[b]!=c)
            {
                flag = true;
            }
        }
    }

    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;

    while(t--)
      solve();

    system("pause");
    return 0;
}