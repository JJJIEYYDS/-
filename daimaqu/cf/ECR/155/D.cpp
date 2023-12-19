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

void solve()
{
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = a[i - 1] ^ a[i];
    }
    ll ans = 0;
    vector<array<ll, 3>> v1(50), v2(50);

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= 32; j++)
        {
            if (a[i] >> j & 1)
            {
                ans = (ans + (((((v1[j][0] * (ll)i - v2[j][0]) % mod + mod) % mod) * (1ll << j)) % mod)) % mod;
                v2[j][1] = (v2[j][1] + i) % mod;
                v1[j][1] = (v1[j][1] + 1) % mod;
            }
            else
            {
                ans = (ans + (((((v1[j][1] * i - v2[j][1]) % mod + mod) % mod) * (1ll << j)) % mod)) % mod;
                v1[j][0] = (v1[j][0] + 1) % mod;
                v2[j][0] = (v2[j][0] + i) % mod;
            }
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
    // cin >> t;

    while (t--)
        solve();

    system("pause");
    return 0;
}