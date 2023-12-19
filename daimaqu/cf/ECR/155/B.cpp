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
    vector<ll> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    ll ans = 1e18;
    ll res = a[1] * n;
    for (int i = 1; i <= n; i++)
    {
        res += b[i];
    }
    ans = min(ans, res);
    res = b[1] * n;
    for (int i = 1; i <= n; i++)
    {
        res += a[i];
    }
    ans = min(ans, res);
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