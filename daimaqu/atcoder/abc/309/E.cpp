#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;

typedef pair<long long ,long long > PLL;
typedef long long ll;
const int N=5e5+10,INF=0x3f3f3f3f;

int n,m,k;

ll h[N],e[N*2],ne[N*2],idx,w[N];
bool st[N];
ll res;

void add(ll a,ll b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

void bfs()
{
    queue<ll> p;
    p.push(1);

    while(p.size())
    {
        ll t = p.front();
        if(w[t]>-1) res++;

        p.pop();

        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(!st[j])
            { 
                st[j]=true;
                w[j]=max(w[j],w[t]-1);
                p.push(j);
            }
        }
    }

}
void solve()
{
    cin >> n >> m;

    memset(h,-1,sizeof h);
    memset(w,-1,sizeof w);

    for(int i=2;i<=n;i++)
    {
        ll x;
        cin>>x;
        add(x,i);
    }

    while(m--)
    {
        ll x,y;
        cin>>x>>y;

        w[x] = max(w[x] , y);

    }

    bfs();

    cout<<res<<endl;
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
