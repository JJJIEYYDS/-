#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <array>

using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef unsigned long long ULL;
typedef long long ll;
const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
PLL a[N];

bool check(ll x)
{
    // cout << x << endl;
    ll res1 = 0, res2 = x;
    for (int i = 1; i <= n; i++)
    {
        // cout << res1 << ' ' << res2 << endl;
        // cout << a[i].first << ' ' << a[i].second << endl;
        if (a[i].first > res2 || a[i].second < res1)
        {
            return false;
        }
        // cout << 1 << endl;
        res1 = max(res1, a[i].first), res2 = min(res2, a[i].second);
        // cout << res1 << ' ' << res2 << endl;
        res1 = max(0ll, res1 - x), res2 = res2 + x;
    }
    return true;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    ll l = 0, r = 1e9 + 100;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
            l = mid + 1;
    }
    cout << l << endl;
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