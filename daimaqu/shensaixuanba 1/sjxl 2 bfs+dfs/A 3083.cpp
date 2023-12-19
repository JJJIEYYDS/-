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

char s[50][50];

int d[50][50];

int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int cnt1=0,cnt2=0,cnt3=0;

bool flag;

int step_l[4][4][2]=
{
    {{0,-1},{-1,0},{0,1},{1,0}},
    {{0,1},{1,0},{0,-1},{-1,0}},
    {{1,0},{0,-1},{-1,0},{0,1}},
    {{-1,0},{0,1},{1,0},{0,-1}}
};

int step_r[4][4][2]=
{
    {{0,1},{-1,0},{0,-1},{1,0}},
    {{0,-1},{1,0},{0,1},{-1,0}},
    {{-1,0},{0,-1},{1,0},{0,1}},
    {{1,0},{0,1},{-1,0},{0,-1}}
};
int cl[4][4]={{2,0,3,1},{3,1,2,0},{1,2,0,3},{0,3,1,2}};//改变方向之后问题
int cr[4][4]={{3,0,2,1},{2,1,3,0},{0,2,1,3},{1,3,0,2}};

void bfs()
{
    queue<pair<int,int> > p;

    for(int i=0;i<50;i++)
    {
       for(int j=0;j<50;j++)
           {
            d[i][j]=-1;
           }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='S') 
            {
                p.push({i,j});
                d[i][j]=0;
            }
        }
    }

    while(p.size())
    {
        pair<int,int> t=p.front();
        p.pop();
        if(s[t.first][t.second]=='E')
        {
            cnt3=d[t.first][t.second];
            return;
        }
        
        for(int i=0;i<4;i++)
        {
            int x=dx[i]+t.first,y=dy[i]+t.second;
        
            if(x<=n&&x>=1&&y>=1&&y<=m&&d[x][y]==-1&&(s[x][y]=='.'||s[x][y]=='E'))
            {
                d[x][y]=d[t.first][t.second]+1;
                p.push({x,y});
            }
            
        }

    }
}

void dfs1(int x,int y,int dir)
{
    cnt1++;//具有优先级
    if(s[x][y]=='E')
    {
        flag=true;
        return ;
    }

    for(int i=0;i<4;i++)
    {
        int nx=x+step_l[dir][i][0];
        int ny=y+step_l[dir][i][1];
        if(nx>=1&&nx<=n&&ny<=m&&ny>=1&&!flag&&s[nx][ny]!='#')
        dfs1(nx,ny,cl[dir][i]);
    }
}

void dfs2(int x,int y,int dir)
{
    cnt2++;

    if(s[x][y]=='E')
    {
        flag=true;
        return ;
    }

     for(int i=0;i<4;i++)
    {
        int nx=x+step_r[dir][i][0];
        int ny=y+step_r[dir][i][1];
        if(nx>=1&&nx<=n&&ny<=m&&ny>=1&&!flag&&s[nx][ny]!='#')
        dfs2(nx,ny,cr[dir][i]);
    }
}

void solve()
{
    cin>>m>>n;

    flag=false;

    int t1=0,t2=0,initdir;

    cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>s[i][j];
            if(s[i][j]=='S') 
            {
                t1=i,t2=j;
            }
        }
    }

    bfs();

    if(t1==1)
    {
        initdir=1;
    }
    else if(t1==n)
    {
        initdir=0;
    }
    else if(t2==1)
    {
        initdir=3;
    }
    else if(t2==m)
    {
        initdir=2;
    }
    dfs1(t1,t2,initdir);
    flag=0;
    dfs2(t1,t2,initdir);
    cout<<cnt1<<' '<<cnt2<<' '<<cnt3+1<<endl;


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