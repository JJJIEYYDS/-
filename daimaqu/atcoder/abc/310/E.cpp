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

const int N=1e6+10;

int n,m,k;

char s[N];

int dp[N][2];

void solve()
{
    cin >> n >> s + 1;

    ll res=0;

    for(int i = 1; i <= n; i++ )
    {
        if( s[i] == '0' )
        {
            int x0 = dp[i-1][0], x1 = dp[i-1][1];

            dp[i][0] = 1, dp[i][1] = x0 + x1;
            res += dp[i][1];

        }
        else
        {
            int x0 = dp[i-1][0], x1 = dp[i-1][1];

            dp[i][0] = x1, dp[i][1] = x0 + 1;
            res += dp[i][1];

        }
    }

    cout<<res<<endl;

    

    

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