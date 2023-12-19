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
const int N = 1e6+10, INF = 0x3f3f3f3f, mod= 998244353 ;

ll n,m,k;

ll dp[N][2];

void solve()
{
    cin >> n >> m;
    ll res=0;
    if(n==2)
    {
        res=(m*(m-1))%mod;
        cout<<res<<endl;
        return ;
    }
    else if(n==3)
    {
        res=(m*(m-1)*(m-2))%mod;
        cout<<res<<endl;
        return ;
    }

    dp[1][0]=m;
    for(int i=2;i<=n;i++)
    {
        dp[i][0] =  dp[i-1][1]  % mod;
        dp[i][1] = ( (dp[i-1][1]*(m-2))%mod + (dp[i-1][0]*(m-1))%mod)%mod; 
    }

    cout<<dp[n][1]%mod<<endl;



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