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
typedef unsigned long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

ll n, m, k, q;

ll y[70];

void init()
{
    y[0] = 1;
    for (int i = 1; i <= 64; i++)
    {
        y[i] = y[i - 1] * 2;
    }
}

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a;
        b >>= 1;
        a = a * a;
    }
    return res;
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    ll ans = 0;

    ll t1 = 0, t2 = 0;
    for (int i = 0; i < 64; i++)
    {
        if (qpow(2, i) > l)
        {
            t1 = i - 1;
            break;
        }
    }
    for (int i = 0; i < 64; i++)
    {
        if (qpow(2, i) > r)
        {
            t2 = i - 1;
            break;
        }
    }

    for (int i = t1; i <= t2; i++)
    {
        ll L = max(qpow(2, i), l), R = min(qpow(2, i + 1) - 1, r);
        ll l1 = 1, l2 = 1;
        while (qpow(i, l1) * i <= L)
        {
            l1++;
        }
        while (qpow(i, l2) * i <= R)
        {
            l2++;
        }
        // cout << l1 << ' ' << l2 << endl;
        for (int j = l1; j <= l2; j++)
        {
            ll t3 = max(qpow(i, j), L), t4 = min(R, qpow(i, j + 1) - 1);
            // cout << t3 << ' ' << t4 << endl;
            ans = (ans + (t4 - t3 + 1) * j % mod) % mod;
        }
    }
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