#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=3e5+10,INF=0x3f3f3f3f;

int n1,n2,m,k;

int h[N],e[N*2],ne[N*2],idx;
int d[N];
int t1,t2;
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

int bfs(int n)
{
    queue<int> p;
    memset(d,-1, sizeof d);
    p.push(n);
    int res=0;
    d[n]=0;
    while(p.size())
    {
        int t=p.front();
        p.pop();
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(d[j]==-1)
            {
                p.push(j);
                d[j]=d[t]+1;
                res=max(res,d[j]);
            }
        }
    }
    return res;

}
void solve()
{
    memset(h,-1,sizeof h);
    cin>>n1>>n2>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    t1=bfs(1);

    t2=bfs(n1+n2);

    cout<<t1+t2+1<<endl;


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