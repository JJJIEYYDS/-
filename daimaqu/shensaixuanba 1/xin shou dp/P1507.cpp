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
const int N=500,INF=0x3f3f3f3f;

int n,m,k;
int h,t;

int a[N], b[N], c[N];

int dp[N][N];

void solve()
{
    cin >> h >> t;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j=h;j>=a[i];j--)
        {
            for(int k=t;k>=b[i];k--)
            dp[j][k]=max(dp[j][k],dp[j-a[i]][k-b[i]]+c[i]);
        }
    }

    cout<<dp[h][t]<<endl;
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