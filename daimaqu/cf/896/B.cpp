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
ll s, g;
void solve()
{
    cin >> n >> k >> s >> g;
    vector<PLL> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    ll ans = abs(a[s].first - a[g].first) + abs(a[s].second - a[g].second);
    if (k <= 1)
    {
        cout << ans << endl;
        return;
    }

    ll t1 = 1e18, t2 = 1e18;
    for (int i = 1; i <= k; i++)
    {
        if (abs(a[s].first - a[i].first) + abs(a[s].second - a[i].second) < t1)
        {
            t1 = abs(a[s].first - a[i].first) + abs(a[s].second - a[i].second);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        if (abs(a[g].first - a[i].first) + abs(a[g].second - a[i].second) < t2)
        {
            t2 = abs(a[g].first - a[i].first) + abs(a[g].second - a[i].second);
        }
    }
    ans = min(ans, t2 + t1);
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