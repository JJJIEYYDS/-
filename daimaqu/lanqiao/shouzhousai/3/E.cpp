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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll t1;

bool check(ll mid)
{
    ll t2 = (t1 - 2) * (t1 - 1) / 2;
    if (mid == 2 * n)
    {
        return t2 >= k;
    }
    else
    {
        return t2 - (t1 - 2 - (mid - t1)) * (t1 - 1 - (mid - t1)) / 2 >= k;
    }
}

void solve()
{
    cin >> n >> k;
    t1 = n + 1;

    if ((t1 - 1) * (t1) / 2 >= k)
    {
        ll l = 2, r = t1;
        while (l < r)
        {
            ll mid = (l + r) >> 1;
            if ((mid - 1) * mid / 2 >= k)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        k -= (l - 2) * (l - 1) / 2;
        cout << k << ' ' << l - k << endl;
    }
    else
    {
        k -= (t1 - 1) * t1 / 2;
        ll t2 = (t1 - 2) * (t1 - 1) / 2;

        ll l = t1 + 1, r = 2 * n;
        while (l < r)
        {
            ll mid = (l + r) >> 1;
            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        // cout << l << endl;
        ll t = 2 * n - l + 1;

        k -= t2 - (t1 - 2 - (l - 1 - t1)) * (t1 - 1 - (l - 1 - t1)) / 2;
        cout << n - t + 1 + k - 1 << ' ' << l - (n - t + 1 + k - 1) << endl;
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

    // system("pause");
    return 0;
}