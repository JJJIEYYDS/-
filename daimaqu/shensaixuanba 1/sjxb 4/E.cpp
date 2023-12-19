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
ll a, b;

bool check(__int128 k, __int128 j)
{
    __int128 res = 1;
    while (j)
    {
        if (j & 1)
        {
            res = (res * k);
            if (res >= m)
                return true;
        }
        j >>= 1;
        k = k * k;
    }

    if (res - 1 >= m)
    {
        return true;
    }
    return false;
}
void solve()
{
    cin >> n >> k >> m >> a >> b;
    if (k == 1)
    {
        if (n % m != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return;
    }
    ll ans = 2e18;
    if (n % m == 0)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i <= 70; i++)
    {
        if (n == 0)
        {
            ans = min(ans, b * i);
            break;
        }
        ll d = n % m, q = 1;
        for (int j = 0;; j++)
        {
            ll t = (m - d) % m;
            if (t <= q - 1)
            {
                ans = min(ans, j * a + b * i);
                break;
            }
            q *= k;
            d = ((n % m) * (q % m)) % m;
        }
        n /= k;
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

    while (t--)
        solve();

    system("pause");
    return 0;
}