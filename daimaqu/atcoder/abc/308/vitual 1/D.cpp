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

char s[800][800];

int dx[4]={0,-1,0,1},dy[]={1,0,-1,0};

char str[7]="snuke";
bool st[800][800];


void bfs()
{
    if(s[1][1]!='s') 
    {
        cout<<"No"<<endl;
        return ;
    }

    queue<pair<pair<int,int>,int> > p;
    
    p.push({{1,1},0});

    while(p.size())
    {
        pair<pair<int,int>,int> t=p.front();

        p.pop();
        //cout<<t.first.first<<' '<<t.first.second<<' '<<t.second<<' '<<str[(t.second-1)%5+1]<<endl;
        if(t.first.first==n&&t.first.second==m)
        {
            cout<<"Yes"<<endl;
            return ;
        }

        for(int i=0;i<4;i++)
        {
            int x=t.first.first+dx[i],y=t.first.second+dy[i],d=t.second+1;

            if(!st[x][y]&&x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]==str[((d-1)%5+1)%5])
            {
                //cout<<x<<' '<<y<<endl;
                st[x][y]=true;
                
                p.push({{x,y},d});
            }
        }
    }

    cout<<"No"<<endl;

}
void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
       cin>>s[i]+1;
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