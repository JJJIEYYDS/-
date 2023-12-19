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
const int N=1e5+10,INF=0x3f3f3f3f,mod=998244353;

ll n,m,k,q;
int h[N],e[N*2],ne[2*N],w[N*2],idx;
bool st[N];
int dis1[N];
int dis2[N];

void add(int a,int b,int c)
{
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}

void dijkstra(int u,int dis[])
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF,st[i]=0;
    }
    
    dis[u]=0;
    priority_queue<PII,vector<PII>,greater<PII> > p;
    p.push({0,u});


    while(p.size())
    {
        PII t = p.top();
        p.pop();
        int t1=t.first,t2=t.second;
        if(st[t2]) continue;
        st[t2]=true;

        for(int i=h[t2];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dis[j]>t1+w[i])
            {
                dis[j]=t1+w[i];
                p.push({dis[j],j});
            }
        }
    }
    
}


void solve()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    dijkstra(1,dis1);

    dijkstra(n,dis2);
    
    int temp=INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=h[i];j!=-1;j=ne[j])
        {
            int t=e[j];
            int w1=dis1[i]+w[j]+dis2[t];
            if(w1==dis1[n]) continue;
            temp = min(temp,w1);
        }
    }

    cout<<temp<<endl;

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