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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll p[N];
map<ll, ll> mp;
vector<ll> v;

ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}
void fun(ll x)
{
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i)
            continue;
        v.push_back(i);
        mp[i] = 1;
        while (x % i == 0)
            mp[i] *= i, x /= i;
    }
    if (x > 1)
        v.push_back(x), mp[x] = x;
}
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1, gcd;
    gcd = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return gcd;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    ll lc = p[1];
    for (int i = 2; i <= n; i++)
    {
        lc = lcm(lc, p[i]);
    }

    fun(2 * lc);
    ll ans = 2e18;

    for (int i = 0; i < 1ll << (v.size()); i++)
    {
        ll a = 1;
        for (int j = 0; j < v.size(); j++)
        {
            if (i >> j & 1)
                a *= mp[v[j]];
        }

        ll b = 2 * lc / a;
        ll x, y, d;
        d = exgcd(a, b, x, y);
        x = -x;
        x = (x % (b / d) + b / d) % (b / d);

        if (a * x)
            ans = min(a * x, ans);
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