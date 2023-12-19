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
const int N = 50, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q, x;
ll g[N][N];
ll sum[N][N];

void solve()
{
    cin >> n >> m;
    vector<ll> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            g[i][j] = a[i] * b[j];
        }
    }
    cin >> x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + g[i][j];
        }
    }
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            for (ll k = i; k <= n; k++)
            {
                for (ll v = j; v <= m; v++)
                {
                    if (sum[k][v] - sum[i - 1][v] - sum[k][j - 1] + sum[i - 1][j - 1] <= x)
                    {
                        ans = max(ans, (k - i + 1) * (v - j + 1));
                    }
                }
            }
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