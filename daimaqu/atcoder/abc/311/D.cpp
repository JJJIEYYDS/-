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
const int N=700,INF=0x3f3f3f3f;

int n,m,k;

char s[N][N];
int dx[]={0,-1,0,1},dy[]={1,0,-1,0};
bool st[N][N];

ll res,ans=1;
bool flag;
void dfs(int x1,int y1)
{
    st[x1][y1]=true;
    
    for(int i=0;i<4;i++)
    {
        int x = x1 + dx[i], y = y1+ dy[i];
        if(x<1||y<1||x>n||y>m||s[x][y]=='#') continue;
        while(s[x][y]=='.'||s[x][y]=='a')
        {
            if(s[x][y]=='.')
            {
                 s[x][y]='a';
                 res++;
                 ans=max(ans,res);
            }
            x+=dx[i];
            y+=dy[i];
        }
        x-=dx[i],y-=dy[i];
        if(!st[x][y]) dfs(x,y);
        
        
    }
}

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>s[i]+1;
    }

    s[2][2] = 'a';
    res=1,ans=1;

    dfs(2,2);

    cout<<ans<<endl;
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