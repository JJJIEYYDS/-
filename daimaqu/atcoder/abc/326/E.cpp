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

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = a * res % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
ll inv(ll x)
{
    return qpow(x, mod - 2);
}

void solve()
{
    cin >> n;
    vector<ll> a(n + 1); //*(1/n)相当于乘上(1/n)的逆元
    ll invv = inv(n);
    ll p = invv;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + p * a[i]) % mod;
        p = (p + p * invv) % mod;
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