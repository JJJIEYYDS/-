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
ll p, l1, t1;
__int128 res1;

bool check(__int128 x)
{
    __int128 res = (n - x);
    if (res * l1 >= p)
    {
        return true;
    }
    if (res * l1 + min(res * 2, res1) * t1 >= p)
    {
        return true;
    }
    return false;
}
void solve()
{
    cin >> n >> p >> l1 >> t1;
    res1 = ceil(n / 7.0);
    // cout << (ll)res1 << endl;
    ll l = 0, r = n + 10;
    while (l < r)
    {
        ll mid = l + r + 1 >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
            r = mid - 1;
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