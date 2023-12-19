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

ll n, m, k, q;
ll g[N][N];
ll d[N][N][4];
ll dx[] = {1, 0}, dy[] = {0, 1};
ll e = -1e18;

ll dfs(ll x, ll y, ll k)
{
    // cout << 1111 << ' ' << i << ' ' << j << ' ' << k << endl;
    if (k == -1)
    {
        return e;
    }
    if (d[x][y][k] != e)
    {
        return d[x][y][k];
    }
    if (x == n && y == m)
    {
        return g[n][m];
    }

    for (int i = 0; i < 2; i++)
    {
        ll x1 = dx[i] + x, y1 = dy[i] + y;
        if (x1 <= n && y1 <= m)
        {
            if (__gcd(g[x1][y1], g[x][y]) == 1)
            {
                d[x][y][k] = max(dfs(x1, y1, k - 1) + g[x][y], d[x][y][k]);
            }
            else
            {
                d[x][y][k] = max(dfs(x1, y1, k) + g[x][y], d[x][y][k]);
            }
        }
    }
    return d[x][y][k];
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

    // system("pause");
    return 0;
}