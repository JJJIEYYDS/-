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

void solve()
{
    cin >> n;
    vector<vector<ll>> v(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;

        for (int j = 1; j <= x; j++)
        {
            ll y;
            cin >> y;
            v[i].push_back(y);
        }
    }
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() >= m)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, v[i][j]);
            }
        }
    }
    if (ans == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= min((ll)v[i].size() - 1, m); j++)
            {
                ans = max(ans, v[i][j]);
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