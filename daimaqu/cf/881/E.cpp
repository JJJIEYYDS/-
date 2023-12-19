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

ll c[N];
ll b[N];

struct segment
{
    int l, r;
} s[N];

bool check(int x)
{
    memset(c, 0, sizeof c);
    for (int i = 1; i <= x; i++)
    {
        c[b[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        c[i] += c[i - 1];
    }

    for (int i = 1; i <= m; i++)
    {
        int x = c[s[i].r] - c[s[i].l - 1], y = (s[i].r - s[i].l + 1);
        if (y - x < x)
            return true;
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> s[i].l >> s[i].r;
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> b[i];
    }

    int l = 1, r = q + 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        // cout << 11111 << ' ' << mid << endl;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (l > q)
        cout << -1 << endl;
    else
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