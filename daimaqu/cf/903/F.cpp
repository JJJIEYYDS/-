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
vector<vector<ll>> g;
vector<bool> st;
vector<ll> mx, ans;

void dfs(int u, int fa)
{

    if (st[u])
        mx[u] = 0;
    for (auto j : g[u])
    {
        if (j == fa)
            continue;
        dfs(j, u);
        mx[u] = max(mx[u], mx[j] + 1);
    }
}

void dfs1(ll u, ll fa, ll pre)
{
    // cout << u << ' ' << fa << ' ' << pre << endl;
    if (st[u])
        pre = max(pre, 0ll);
    ans[u] = max(mx[u], pre);
    ll mx1 = pre, mx2 = -INF;

    for (auto j : g[u])
    {
        if (j == fa)
            continue;
        if (mx[j] + 1 >= mx1)
        {
            mx2 = mx1;
            mx1 = mx[j] + 1;
        }
        else if (mx[j] + 1 > mx2)
        {
            mx2 = mx[j] + 1;
        }
    }

    for (auto j : g[u])
    {
        if (j == fa)
            continue;
        if (mx[j] + 1 == mx1)
        {
            dfs1(j, u, mx2 + 1);
        }
        else
        {
            dfs1(j, u, mx1 + 1);
        }
    }
}

void solve()
{
    cin >> n >> k;
    st = vector<bool>(n + 1);
    g = vector<vector<ll>>(n + 1);
    mx = vector<ll>(n + 1, -INF);
    ans = vector<ll>(n + 1);

    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        st[x] = true;
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(1, -1);

    dfs1(1, -1, -INF);
    sort(ans.begin() + 1, ans.end());
    cout << ans[1] << endl;
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