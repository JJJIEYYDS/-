#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,k;

void solve()
{
    cin>>n>>k;

    vector<ll> a;
    vector<vector<ll>> dp(n,vector<ll>(k+1));
    
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            ll w=(a[i]-a[j])*(a[i]-a[j]);
            int c=i-j-1;

            for(int x=c;x<=k;x++)
            {
                dp[i][x]=max(dp[i][x],dp[j][x-c]+w);
            }
        }
    }

    cout<<dp[n-1][k]<<endl;
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