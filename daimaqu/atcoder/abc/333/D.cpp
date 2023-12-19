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
const int N = 3e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll s[N];
vector<vector<ll>> edges;
ll dfs(int u, int fa)
{
    s[u] = 1;
    for (auto x : edges[u])
    {
        if (x == fa)
            continue;
        s[u] += dfs(x, u);
    }
    return s[u];
}
void solve()
{
    cin >> n;
    edges = vector<vector<ll>>(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(1, 0);
    ll ans = 0;

    vector<ll> a;
    for (auto x : edges[1])
    {
        a.push_back(s[x]);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 1; i++)
    {
        ans += a[i];
    }
    cout << ans + 1 << endl;
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