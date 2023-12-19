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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
double x, y;

void solve()
{
    cin >> n >> x >> y;
    x *= 0.01;
    vector<double> a(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end(), greater<double>());
    double res1 = 0, res2 = 0;
    bool flag1 = 0, flag2 = 0;
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        res1 = a[i] - a[i] * x;
        res2 = min(y, a[i]);

        if (!flag1)
        {
            if (!flag2)
            {
                if (res1 >= res2)
                {
                    flag1 = true;
                    ans += a[i] * x;
                }
                else
                {
                    flag2 = true;
                    ans += a[i] - res2;
                }
            }
            else
            {
                ans += a[i] * x;
                flag1 = true;
            }
        }
        else
        {
            if (!flag2)
            {
                ans += a[i] - y;
                flag2 = true;
            }
            else
            {
                ans += a[i];
            }
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
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