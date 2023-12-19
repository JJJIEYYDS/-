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
#define int long long
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll c[25];

ll a[N];
ll v[N], w[N];
void init()
{
    c[0] = 1;
    for (int i = 1; i <= 25; i++)
    {
        c[i] = c[i - 1] * 2;
    }
}

void solve()
{
    cin >> n >> m >> q;

    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    ll pre = 0;
    a[0] = 1;
    vector<ll> p;
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
        {
            if (a[pre])
            {
                p.push_back(i - pre - 1);
            }
            else
            {
                p.push_back(i - pre);
            }
            pre = i;
        }
    }

    if (n - pre > 0)
        p.push_back(n - pre);

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = c[x], w[i] = y;
    }
    ll ans = 0;
    for (int i = 0; i < p.size(); i++)
    {
        vector<ll> dp(p[i] + 10, 0);
        for (int j = 1; j <= m; j++)
        {
            for (int k = v[j]; k <= p[i]; k++)
            {
                dp[k] = max(dp[k], dp[k - v[j]] + w[j]);
            }
        }
        ans += dp[p[i]];
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    init();

    while (t--)
        solve();

    system("pause");
    return 0;
}