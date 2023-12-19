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
const int N=500,INF=0x3f3f3f3f;

int n,m,k;

char s[N][N];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>s[i]+1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='#'||s[i][j]=='?')
            {
                bool flag=false;
                if(i+2>n||j+2>m||i+8>n||j+8>m) continue;
                for(int k=i;k<=i+2;k++)
                {
                    for(int u=j;u<=j+2;u++)
                    {
                        if(s[k][u]=='.') flag=true;
                    }
                }
                if(flag) 
                {
                    continue;
                }
                if(j+3>m) continue;
                for(int k=0;k<=3;k++)
                {
                    if(s[i+k][j+3]=='#') flag=true;
                }
                if(flag) continue;
                if(i+3>n) continue;
                for(int k=0;k<=3;k++)
                {
                    if(s[i+3][j+k]=='#') flag=true;
                }
                if(flag) continue;

                for(int k=i+6;k<=i+2+6;k++)
                {
                    for(int u=j+6;u<=j+2+6;u++)
                    {
                        if(s[k][u]=='.') flag=true;
                    }
                }
                if(flag) continue;

                for(int k=0;k<=3;k++)
                {
                    if(s[i+5][j+5+k]=='#') flag =true;
                }

                if(flag) continue;

                for(int k=0;k<=3;k++)
                {
                    if(s[i+5+k][j+5]=='#') flag = true;
                }

                if(flag) continue;

                cout<<i<<' '<<j<<endl;
            }
        }
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