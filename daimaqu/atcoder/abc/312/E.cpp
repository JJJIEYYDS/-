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
const int N=150,INF=0x3f3f3f3f,mod=998244353;

int n,m,k;
int g[N][N][N];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        for(int x=a;x<d;x++)
        {
            for(int y=b;y<e;y++)
            {
                for(int z=c;z<f;z++)
                {
                    g[x][y][z]=i;
                }
            }
        }
    }
    vector<set<int>> ans(n+1);

    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
        {
            for(int k=0;k<=100;k++)
            {
                int temp=g[i][j][k];
                if(temp)
                {
                    int a=g[i+1][j][k];
                    int b=g[i][j+1][k];
                    int c=g[i][j][k+1];
                    if(a&&a!=temp)
                    {
                        ans[temp].insert(a);
                        ans[a].insert(temp);
                    }
                    if(b&&b!=temp)
                    {
                        ans[temp].insert(b);
                        ans[b].insert(temp);
                    }
                    if(c&&c!=temp)
                    {
                        ans[temp].insert(c);
                        ans[c].insert(temp);
                    }
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i].size()<<endl;
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