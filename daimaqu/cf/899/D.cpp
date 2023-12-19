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
ll a[N], b[N], s[N];

vector<vector<ll>> edges;
vector<ll> ans;

ll dfs(int u, int fa)
{
    s[u] = 1;
    for (auto x : edges[u])
    {
        if (x == fa)
            continue;
        ll s1 = dfs(x, u);
        s[u] += s1;
    }
    return s[u];
}

ll dfs1(int u, int fa)
{
    if (u != 1)
        b[u] = s[u] * ((a[fa] ^ a[1]) ^ a[u] ^ a[1]);
    else
        b[u] = 0;
    // cout << u << ' ' << b[u] << endl;
    for (auto x : edges[u])
    {
        if (x == fa)
            continue;

        ll s1 = dfs1(x, u);

        b[u] += s1;
    }
    return b[u];
}

void dfs2(int u, int fa)
{
    for (auto v : edges[u])
    {
        if (v == fa)
            continue;
        ans[v] = (ans[u] - s[v] * (a[u] ^ a[v])) + (n - s[v]) * (a[u] ^ a[v]);
        dfs2(v, u);
    }
}
void solve()
{
    cin >> n;
    ans = vector<ll>(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    edges = vector<vector<ll>>(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, 0);
    ans[1] = dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    edges.clear();
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