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
    ll ans = 0, mx = 0;
    ll res = 0;
    if (n == 2)
    {
        cout << 2 << endl;
        return;
    }
    for (ll i = 1; i <= n; i++)
    {
        res += i * i;
        mx = max(mx, i * i);
        ll res1 = 0, cnt1 = i, mx1 = 0;
        for (ll j = n; j > i; j--)
        {
            cnt1++;
            res1 += cnt1 * j;
            mx1 = max(mx1, cnt1 * j);
        }
        ans = max(ans, res + res1 - max(mx, mx1));
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