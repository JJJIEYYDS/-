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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;

vector<ll> e[N];
ll s[N];

void dfs(int u, int fa)
{
    s[u] = 0;
    if (e[u].size() == 1 && u != 1)
    {
        s[u] = 1;
        return;
    }

    for (auto x : e[u])
    {
        if (x == fa)
            continue;
        dfs(x, u);
        s[u] += s[x];
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(1, 0);

    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;

        cout << s[x] * s[y] << endl;
    }
    memset(e, 0, sizeof e);
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