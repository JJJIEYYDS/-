#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
const int N = 20, M = (1 << N), INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll dp[M][N];
ll w[N][N];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
        }
    }

    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
            {
                for (int k = 0; k < n; k++)
                {
                    if (i >> k & 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + w[k][j]); // 更新最短距离
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;

    while (t--)
        solve();

    system("pause");
    return 0;
}