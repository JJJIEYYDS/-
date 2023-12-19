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
const int N = 20, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll d[N][N];
bool st[N];

ll ans = 0;
void dfs(ll u, ll sum)
{
    if (st[u])
    {
        dfs(u + 1, sum);
        return;
    }
    if (u > n)
    {
        ans = max(ans, sum);
        return;
    }
    for (int i = u + 1; i <= n; i++)
    {
        if (!st[u] && !st[i])
        {
            st[u] = true;
            st[i] = true;
            dfs(u + 1, sum + d[u][i]);
            st[u] = false;
            st[i] = false;
        }
    }
    if (n % 2)
        dfs(u + 1, sum);
}
void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }
    dfs(1, 0);

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