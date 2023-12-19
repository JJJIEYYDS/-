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
const int N=3010,INF=0x3f3f3f3f,mod=998244353;

int n,m,k;
string s;
ll f[N][N];

void solve()
{
    cin>>s;
    f[0][0]=1;
    s=' '+s;

    for(int i=1;i<s.size();i++)
    {
        for(int j=0;j<s.size();j++)
        {
            if(s[i]=='(') 
            {
                if(j!=0)
                {
                    f[i][j]=f[i-1][j-1];
                }
                else f[i][j]=0;
            }
            else if(s[i]==')')
            {
                if(j!=s.size()-1)
                {
                    f[i][j]=f[i-1][j+1];
                }
                else f[i][j]=0;
            }
            else 
            {
                if(j!=0)
                {
                    f[i][j]=(f[i][j]+f[i-1][j-1])%mod;
                }
                if(j!=s.size()-1)
                {
                    f[i][j]=(f[i][j]+f[i-1][j+1])%mod;
                }
            }
        }
    }

    cout<<f[s.size()-1][0]<<endl;
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