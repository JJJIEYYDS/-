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

int a[500][500];
bool st[500][500];

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

struct node
{
    int x,y,h;
    bool operator<(const node& p) const
    {
        return h>p.h;
    }

}temp;

priority_queue<node> p;

void bfs()
{
    ll res=0;
    queue<node> q;

    while(p.size())
    {
        q.push(p.top());

        node tt=p.top();
        int h=tt.h;
        p.pop();
        while(q.size())
        {
            node t=q.front();
            q.pop();
            node ttt;
        
            for(int i=0;i<4;i++)
            {
                ttt.x=t.x+dx[i],ttt.y=t.y+dy[i],ttt.h=a[ttt.x][ttt.y];
                if(!st[ttt.x][ttt.y]&&ttt.x<=n&&ttt.x>=1&&ttt.y>=1&&ttt.y<=m)
                {
                    st[ttt.x][ttt.y]=true;

                    if(a[ttt.x][ttt.y]<h)
                    {
                        res+=h-ttt.h;
                        q.push(ttt);

                    }
                    else 
                    p.push(ttt);
                }
            }
        }
    }
    cout<<res<<endl;
}

void solve()
{
    cin>>m>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=m;i++)
    {
        temp.x=1;
        temp.y=i;
        temp.h=a[1][i];
        st[1][i]=true;

        p.push(temp);

        temp.x=n;
        temp.y=i;
        temp.h=a[n][i];
        st[n][i]=true;

        p.push(temp);
    }

    for(int i=2;i<=n-1;i++)
    {
        temp.x=i;
        temp.y=1;
        temp.h=a[i][1];
        st[i][1]=true;

        p.push(temp);

        temp.x=i;
        temp.y=m;
        temp.h=a[i][m];
        st[i][m]=true;

        p.push(temp);
    }

    bfs();

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