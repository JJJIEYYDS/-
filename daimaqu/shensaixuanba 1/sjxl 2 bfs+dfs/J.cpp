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
int res;

int d[50][5];
bool st[50][50];

int dir[8][2] = {
    {-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}
};

int dfs(int s,int x,int y)
{
    if(s==n*m)
    {
        return 1;
    }

    for(int i=0;i<8;i++)
    {
        int tx=x+dir[i][0],ty=y+dir[i][1];

        if(tx>=0&&tx<n&&ty>=0&&ty<m&&!st[tx][ty])
        {
            st[tx][ty]=true;
            
            if(dfs(s+1,tx,ty)) 
            {
                d[s][0]=tx,d[s][1]=ty;
                return 1;
            }
            st[tx][ty]=false;
        }
        
    }
    return false;

}
void solve()
{
    res++;
    cin>>n>>m;

    cout<<"Scenario #"<<res<<":"<<endl;

    memset(st,0,sizeof st);

    st[0][0]=true;

    d[0][0]=0;
    d[0][1]=0;

    if(dfs(1,0,0))
    {
        for(int i=0;i<n*m;i++)
        cout<<(char)(d[i][1]+'A')<<d[i][0]+1;
    }
    else
    {
        cout<<"impossible";
    }
    cout<<endl;
    cout<<endl;
    


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