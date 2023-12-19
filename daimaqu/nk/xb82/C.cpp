#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <array>

using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef unsigned long long ULL;
typedef long long ll;
const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll ans[N];
ll dp[N][3];

void init()
{
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        ans[i] = (ans[i - 1] * 26 % mod + dp[i - 1][2]) % mod;
        dp[i][0] = (dp[i - 1][0] * 25 % mod + dp[i - 1][1] * 24 % mod + dp[i - 1][2] * 25 % mod) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][2] = dp[i - 1][1];
    }
}
void solve()
{
    cin >> n;
    cout << ans[n] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
        solve();

    system("pause");
    return 0;
}