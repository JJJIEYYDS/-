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

void solve()
{
    cin >> n >> k >> x;
    vector<ll> a(n + 1), mx(k);
    vector<vector<ll>> v(k);
    ll ans = 0, res = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx[i % k] = max(mx[i % k], a[i]);
        v[i % k].push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        res += (mx[i % k] - a[i]);
    }

    if (res > x)
        cout << -1 << endl;
    else
    {
        x -= res;
        for (int i = 0; i < k; i++)
        {
            ll cnt = v[i].size();
            ans = max(ans, mx[i] + x / cnt);
        }
        cout << ans << endl;
    }
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