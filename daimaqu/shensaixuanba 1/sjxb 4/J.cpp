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

ll n, m, k, q, v;
ll h[N], e[N * 2], ne[N * 2], idx;
vector<ll> e[N];

void dfs(int u, int fa, int res)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            e[u].push_back()
                dfs(j, )
        }
    }
}

void solve()
{
    cin >> n >> m >> q >> v;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    dfs(1, 0, 0);
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