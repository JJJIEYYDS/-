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

ll n, m, k, q, p;

void solve()
{
    cin >> n >> k >> p;
    vector<ll> pw(k + 1);
    pw[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        pw[i] = pw[i - 1] * (p + 1);
    }
    vector<ll> dp(pw[k], -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        vector<ll> a(k);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        for (int j = pw[k] - 1; j >= 0; j--)
        {
            ll t = 0;
            for (int s = 0; s < k; s++)
            {
                ll t1 = j / pw[s] % (p + 1);
                ll t2 = min(t1 + a[s], p);
                t += t2 * pw[s];
            }
            if (dp[j] != -1 && (dp[t] == -1 || dp[j] + x < dp[t]))
            {
                dp[t] = dp[j] + x;
            }
        }
    }
    cout << dp[pw[k] - 1] << endl;
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