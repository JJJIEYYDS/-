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
const int N = 5010, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
vector<ll> e[N];
ll s[N];

void dfs(int u, int fa)
{
    s[u] = 1;
    for (auto x : e[u])
    {
        dfs(x, u);
        s[u] += s[x];
    }
}

void solve()
{
    cin >> n;
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        e[x].push_back(i);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        ll num = e[i].size();
        if (num == 0)
            continue;
        vector<ll> a(num + 1);

        for (auto x : e[i])
        {
            a.push_back(s[x]);
        }
        vector<ll> f(n + 1);
        f[0] = 1;

        for (auto it : a)
        {
            for (int j = n; j >= 0; j--)
            {
                if (f[j])
                {
                    f[j + it] = 1;
                }
            }
        }
        ll mx = 0;
        for (int j = n; j >= 0; j--)
        {
            if (f[j])
            {
                mx = max(mx, j * (s[i] - j - 1));
            }
        }
        ans += mx;
    }
    cout << ans << endl;
    memset(e, 0, sizeof e);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    system("pause");
    return 0;
}