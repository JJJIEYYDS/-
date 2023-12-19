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
const int N = 1010, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll g[N][N];
ll s[N][N];

void solve()
{
    ll l;
    cin >> n >> k >> l;
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            g[i][j] = 1;
        }
    }
    for (int u = 1; u <= n; u++)
    {
        ll x, y;
        cin >> x >> y;
        for (int i = x; i <= min(x + k - 1, l); i++)
        {
            for (int j = y; j <= min(y + k - 1, l); j++)
            {
                g[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + g[i][j];
        }
    }
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << s[x + k - 1][y + k - 1] - s[x + k - 1][y - 1] - s[x - 1][y + k - 1] + s[x - 1][y - 1] << endl;
    }
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