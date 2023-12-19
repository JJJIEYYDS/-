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

struct node
{
    int v;
    double bea, val;
};
vector<vector<node>> g(N + 1);

bool check(double x)
{
    vector<double> dp(n + 1, -1e12);
    dp[1] = 0;                   //
    for (int i = 1; i <= n; i++) // 由于u<v
    {
        for (auto [v, be, val] : g[i])
        {
            double t = be - val * x; // 把整体价值转化为单个价值
            dp[v] = max(dp[v], dp[i] + t);
        }
    }

    if (dp[n] >= 0)
        return true;
    return false;
}
void solve()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        double val, be;
        cin >> u >> v >> be >> val;
        g[u].push_back({v, be, val});
    }

    double l = 0, r = 1e10;
    while (r - l > 1e-11) // 枚举最优解k 求和a/求和b<=k
    {
        double mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
            r = mid;
    }
    cout << fixed << setprecision(13) << l << endl;
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