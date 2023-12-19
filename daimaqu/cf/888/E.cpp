//若一个由图中所有点构成的序列 A满足：
//对于图中的每条边 (x,y)，x在 A中都出现在 y之前，则称 A是该图的一个拓扑序列。
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

ll w[N],w1[N],r[N],w2[N];


void solve()
{
    cin>>n>>m;
    vector<vector<ll>> v(n+5);

    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        w1[i]=w[i];
    }

    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        w1[x]=0;
        w[x]=0;
    }

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=1;j<=x;j++)
        {
            int c;
            cin>>c;
            v[c].push_back(i);
            r[i]++;
        }
    }

    queue<ll> q;

    for(int i=1;i<=n;i++)
    {
        if(r[i]==0)
        {
            q.push(i);
        }
    }

    while(q.size())
    {
        ll t = q.front();
        q.pop();

        for(auto x:v[t])
        {
            r[x]--;
            w2[x]+=w1[t];
            if(r[x]==0) 
            {
                q.push(x);
                w1[x]=min(w2[x],w[x]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        w[i]=min(w[i],w1[i]);
        cout<<w[i]<<' ';
    }
    cout<<endl;

    for(int i=1;i<=n;i++)
    {
        v[i].clear();
        w[i]=w1[i]=w2[i]=r[i]=0;
    }

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