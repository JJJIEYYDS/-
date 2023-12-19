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
double a[N];
double res;

bool check(double x)
{
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        b[i] = (a[i] - res) * (a[i] - res) - x;
    }
    sort(b.begin() + 1, b.end());
}
void solve()
{
    cin >> n >> k;
    vector for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        res += a[i];
    }
    res /= k;
    for ()
        sort(a + 1, a + n + 1);
    double l = 0, r = 100000000000000000;
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        // cout << mid << endl;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << fixed << setprecision(10) << l << endl;
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