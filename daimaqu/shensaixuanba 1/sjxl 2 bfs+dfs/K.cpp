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
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;

int a[100][100];
int res;

int t1,t2;

int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

void dfs(int x,int y,int step)
{
    if(step>10)
    {
        return ;
    }

    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i],ty=y+dy[i];

        if(a[tx][ty]==1) continue;\

        while(a[tx][ty]==0||a[tx][ty]==2)
        {
            tx=tx+dx[i],ty=ty+dy[i];
        }

        if(a[tx][ty]==1)
        {
            a[tx][ty]=0;
            dfs(tx-dx[i],ty-dy[i],step+1);
            a[tx][ty]=1;
        }
        if(a[tx][ty]==3)
        {
            res=min(res,step+1);
        }

    }


}

void solve()
{
    while(cin>>m>>n)
    {   
        memset(a,-1,sizeof a);

        if(n==m&&n==0)
        {
            return ;
        }

        res=INF;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];

                if(a[i][j]==2)
                {
                    t1=i,t2=j;
                }
            }
        }

        dfs(t1,t2,0);
        if(res>10)
        {
            cout<<-1<<endl;
        }
        else cout<<res<<endl;
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