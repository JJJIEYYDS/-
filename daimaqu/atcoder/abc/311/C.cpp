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
int a[N];

int h[N],e[2*N],ne[2*N],idx;

int b[N],cnt;
bool st[N];
bool flag1;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}


void dfs(int u)
{
    if(st[u])
    {
        flag1=true;
        bool flag=0;
        int res=0;
        for(int i=0;i<cnt;i++)
        {
            if(b[i]==u) flag=true;
            if(flag) res++;
        }
        flag=0;
        cout<<res<<endl;
        for(int i=0;i<cnt;i++)
        {
            if(b[i]==u) flag=true;
            if(flag)cout<<b[i]<<' ';
        }
        cout<<endl;
        return;
    }
    b[cnt++]=u;
    st[u]=true;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        dfs(j);
        if(flag1) return;
    }
}

void solve()
{
    cin>>n;
    memset(h,-1,sizeof h);//找一个序列暴力用dfs
    memset(st,0,sizeof st);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        add(i,a[i]);
    }

    dfs(1);
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
