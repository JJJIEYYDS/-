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
int s[N][N], sum[N][N];

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            if (c == 'B')
            {
                s[i][j] = 1;
                sum[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
            }
        }
    }

    for (int i = 1; i <= q; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = 0;
        ll h = (c - a + 1);
        ll w = (d - b + 1);

        ll a1 = a % n + 1, b1 = b % n + 1, c1 = c % n + 1, d1 = d % n + 1;
        if (a1 > 1)
            h += a1 - 1;
        if (c1 < n)
            h += n - c1;
        if (b1 > 1)
            w += b1 - 1;
        if (d1 < n)
            w += n1 - d;
        ans += sum[a1 - 1][n] * (w / n);
        ans += (sum[n][n] - sum[c][n]) * (w / n);
        ans += sum[n][b1 - 1] * (h / n);
        ans += (sum[n][n] - sum[1][d1]) * (h / n);
        ans -= sum[a1 - 1][b1 - 1];
        ans -=
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