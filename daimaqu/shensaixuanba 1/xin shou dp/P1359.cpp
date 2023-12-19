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

int a[500][500];

int dp[500];

void solve()
{
    cin>>n;

    memset(dp,0x3f,sizeof dp);

    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        cin>>a[i][j];
    }

    

    for(int i=2;i<=n;i++)
    {
        dp[i]=a[1][i];
    }
    

    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<i;j++)
        {
            dp[i]=min(dp[i],dp[j]+a[j][i]);
        }
    }

    cout<<dp[n]<<endl;


    
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