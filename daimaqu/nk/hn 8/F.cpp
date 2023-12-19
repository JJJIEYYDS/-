#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <bitset>

using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll sum[N][61];

void solve()
{
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        bitset<61> b(a[i]);
        for (int j = 0; j < 61; j++)
        {
            sum[i][j] = sum[i - 1][j] + (b[j] == 1);
        }
    }

    for (int i = 1; i <= q; i++)
    {
        ll ans = 0;
        ll l, r, x;
        cin >> l >> r >> x;
        bitset<61> b(x);
        for (int j = 0; j < 61; j++)
        {
            if (b[j] || (sum[r][j] - sum[l - 1][j] != 0))
                ans += (1 << j);
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
    // cin >> t;

    while (t--)
        solve();

    system("pause");
    return 0;
}