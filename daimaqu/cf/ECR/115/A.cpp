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
const int N=1000,INF=0x3f3f3f3f,mod=998244353;

ll n,m,k,q;

char s[3][N];
bool st[3][N];

int dx[]={-1,0,1,0,1,-1,-1,1},dy[]={0,-1,0,1,1,-1,1,-1};
bool flag;
void bfs()
{
    queue<PII> p;
    p.push({1,1});
    st[1][1]=true;
    while(p.size())
    {
        auto t=p.front();
        p.pop();
        if(t.first==2&&t.second==m)
        {
            cout<<"YES"<<endl;
            return ;
        }
        for(int i=0;i<8;i++)
        {
            int x=t.first+dx[i],y=t.second+dy[i];
            if(!st[x][y]&&x>=1&&x<=2&&y<=m&&y>=1&&s[x][y]!='1')
            {
                st[x][y]=true;
                p.push({x,y});
            }
        }
    }
    cout<<"NO"<<endl;
    
}
void solve()
{
    cin>>m;
    memset(st,0,sizeof st);
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>s[i][j];
        }
    }
    bfs();

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