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

ll phi(ll x)
{
    ll res = x;

    for (ll i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
            res = res / i * (i - 1);
        while (x % i == 0)
            x /= i;
    }
    if (x > 1)
        res = res / x * (x - 1);
    return res;
}

ll qsm(__int128 a, __int128 b, ll p)
{
    __int128 res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }

    return res;
}
void solve()
{
    cin >> n >> m;
    ll g = __gcd(n, m);
    m /= g;
    ll cnt2 = 0, cnt5 = 0;

    while (m % 2 == 0)
    {
        m /= 2;
        cnt2++;
    }
    while (m % 5 == 0)
    {
        m /= 5;
        cnt5++;
    }
    if (m == 1)
    {
        cout << -1 << endl;
        return;
    }
    ll x = phi(m);
    ll ans = x;

    for (ll i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            ll x0 = i, x1 = x / i;
            if (qsm(10, x0, m) == 1)
                ans = min(ans, i);

            if (qsm(10, x1, m) == 1)
                ans = min(ans, x1);
        }
    }

    cout << max(cnt2, cnt5) << ' ' << ans << endl;
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