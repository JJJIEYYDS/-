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
double a[N];
double es = 1e-6;
double f(double x)
{
    double res = 0;
    for (int i = n; i >= 0; i--)
    {
        res += pow(x, i) * a[i];
    }
    return res;
}

void solve()
{
    double l, r;
    cin >> n >> l >> r;
    for (int i = n; i >= 0; i--)
    {
        cin >> a[i];
    }
    while (r - l > es)
    {
        double k = (r - l) / 3.0;
        double mid1 = l + k, mid2 = r - k;

        if (f(mid1) < f(mid2))
        {
            l = mid1;
        }
        else
        {
            r = mid2;
        }
    }
    cout << fixed << setprecision(7) << l << endl;
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