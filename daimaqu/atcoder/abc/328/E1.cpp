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
ll v[10][10];
ll ans = 1e15;
ll x[50];
long long p[N];
long long find(long long x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

void dfs(int u, ll res)
{
    if (u == n)
    {
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
        }
        ll cnt = 1;
        for (int i = 1; i <= n - 1; i++)
        {
            long long pa = find(i), pb = find(p[i]);
            if (pa != pb)
            {
                cnt++;
                p[pa] = pb;
            }
        }
        if (cnt == n - 1)
        {
            ans = min(ans, res);
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != u && v[u][i])
        {
            p[u] = i;
            dfs(u + 1, (res + v[u][i]) % k);
        }
    }
}
void solve()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a][b] = c;
        v[b][a] = c;
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