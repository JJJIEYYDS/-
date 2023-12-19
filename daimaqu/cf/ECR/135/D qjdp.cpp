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
const int N=2010,INF=0x3f3f3f3f,mod=998244353;

ll n,m,k,q;
int dp[N][N];
string s;
int check(int l,int r,int x,int y)
{
    if(dp[x][y]!=2) return dp[x][y];
    if(s[l]==s[r]) return 2;
    if(s[l]<s[r]) return 1;
    return 3;
}
void solve()
{
    cin>>s;
    n=s.size();
    for(int len=2;len<=n;len+=2)
    {
        for(int l=0;l+len-1<n;l++)
        {
            int r=l+len-1;
            if(len==2)
            {
                if(s[l]==s[r])
                {
                    dp[l][r]=2;
                }
                else 
                {
                    dp[l][r]=1;
                }
                continue;
            }
            dp[l][r]=min(max(check(l,r,l+1,r-1),check(l,l+1,l+2,r)),max(check(r,r-1,l,r-2),check(r,l,l+1,r-1)));
        }
    }
    if(dp[0][n-1]==1)
    {
        cout<<"Alice"<<endl;
    }
    else if(dp[0][n-1]==2)
    {
        cout<<"Draw"<<endl;
    }
    else cout<<"Bob"<<endl;
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