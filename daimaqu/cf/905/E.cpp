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

ll n, m, k, q;
ll t[N];

void init()
{
    t[0] = 1;
    for (int i = 1; i <= 60; i++)
    {
        t[i] = t[i - 1] * 2;
    }
}

void solve()
{
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<ll> dp(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            int j;
            for (j = 1; j <= 60; j++)
            {
                // cout << a[i + 1] * t[j] << endl;
                if (a[i + 1] * t[j] >= a[i])
                {
                    break;
                }
            }
            dp[i + 1] = j + dp[i];
        }
        else if (a[i] < a[i + 1])
        {
            int j;
            for (j = 1; j <= 60; j++)
            {
                // cout << a[i + 1] * t[j] << endl;
                if (a[i + 1] < a[i] * t[j])
                {
                    break;
                }
            }
            // cout << t[j] << endl;
            if (dp[i] < j)
                dp[i + 1] = 0;
            else
                dp[i + 1] = dp[i] - j + 1;
        }
        else
        {
            dp[i + 1] = dp[i];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << dp[i] << ' ';
        ans += dp[i];
    }
    // cout << endl;
    cout << ans << endl;
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