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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q, x;
ll qsm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

ll inv(ll x)
{
    return qsm(x, mod - 2) % mod;
}
void solve()
{
    cin >> n >> x;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> dp(x + 10, 0); // dp[i]代表第i秒能够播放歌的概率
    dp[0] = 1;
    for (int i = 1; i <= x + 1; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i >= a[j])
                dp[i] = (dp[i] + dp[i - a[j]] * inv(n) % mod) % mod;
        }
    }

    ll ans = 0;

    for (int i = max(x - a[1] + 1, 0ll); i <= x; i++)
    {
        ans = (dp[i] * inv(n) % mod + ans) % mod;
    }
    cout << ans << endl;
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