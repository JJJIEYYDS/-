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
vector<PLL> e[15];
ll d[15];
bool st[15];

void dfs(int u, int w) // 用dfs处理一个点到任意一个点的最大距离
{
    for (auto [x, y] : e[u])
    {
        if (!st[x])
        {
            st[x] = true;
            d[x] = max(d[x], w + y);
            // cout << u << ' ' << ' ' << x << ' ' << y << ' ' << d[x] << endl;
            dfs(x, w + y);
            st[x] = false;
        }
    }
}
void solve()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(d, 0, sizeof d);
        memset(st, 0, sizeof st);
        st[i] = true;
        dfs(i, 0);
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
                continue;
            // cout << i << ' ' << j << ' ' << d[j] << endl;
            ans = max(ans, d[j]);
        }
    }

    cout << ans << endl;
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