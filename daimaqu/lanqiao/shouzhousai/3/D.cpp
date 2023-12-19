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
typedef long long ll;
const int N = 1010, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, q;
ll g[N][N];
ll d[N][N][4];
ll dx[] = {1, 0}, dy[] = {0, 1};
ll e = -1e18;

ll dfs(ll i, ll j, ll k)
{
    // cout << 1111 << ' ' << i << ' ' << j << ' ' << k << endl;
    if (k == -1)
    {
        return e;
    }
    if (d[i][j][k] != e)
    {
        // cout << d[i][j][k] << endl;
        return d[i][j][k];
    }
    if (i == n && j == m)
    {
        return g[n][m];
    }

    for (int i1 = 0; i1 < 2; i1++)
    {
        ll x1 = dx[i1] + i, y1 = dy[i1] + j;
        if (x1 <= n && y1 <= m)
        {
            if (__gcd(g[x1][y1], g[i][j]) == 1)
            {
                d[i][j][k] = max(dfs(x1, y1, k - 1) + g[i][j], d[i][j][k]);
            }
            else
            {
                d[i][j][k] = max(dfs(x1, y1, k) + g[i][j], d[i][j][k]);
            }
        }
    }
    return d[i][j][k];
}

void solve()
{
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            for (int k = 0; k <= q; k++)
            {
                d[i][j][k] = e;
            }
        }
    }

    ll ans = dfs(1, 1, q);
    if (ans > 0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;

    while (t--)
        solve();

    system("pause");
    return 0;
}