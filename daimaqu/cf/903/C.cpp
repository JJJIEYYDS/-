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
const int N = 1010, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
char s[N][N];
ll a[N / 2][N / 2][30];
void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> s[i][j];
        }
    }
    memset(a, 0, sizeof a);
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 1; j <= n / 2; j++)
        {

            a[i][j][s[i][j] - 'a']++;
            a[i][j][s[j][n - i + 1] - 'a']++;
            a[i][j][s[n - i + 1][n - j + 1] - 'a']++;
            a[i][j][s[n - j + 1][n - (n - i + 1) + 1] - 'a']++;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 1; j <= n / 2; j++)
        {

            ll t = 0;
            bool flag = 0;
            for (int k = 26; k >= 0; k--)
            {

                if (!flag && a[i][j][k])
                {
                    flag = 1;
                    t = k;
                    continue;
                }
                if (a[i][j][k])
                {
                    ans += ((t - k) * a[i][j][k]);
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
    cin >> t;

    while (t--)
        solve();

    system("pause");
    return 0;
}