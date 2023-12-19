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
double pi = 3.141592653589793238;

void solve()
{
    cin >> n;
    if ((n / 2) % 2 == 0)
    {
        double t1 = pi / n * (n / 4);
        double l = 0.5 / sin(PI / n / 2);
        double x = l * sin(res);
        double y = l * cos(res);
        cout << fixed << setprecision(9) << (x + y) * sqrt(2) << endl;
    }
    else
    {
        double t1 = pi / n * (((n / 2) + 1) / 2);
        double l = 0.5 / sin(PI / n / 2);
        double x = l * sin(res);
        double y = l * cos(res);
        cout << fixed << setprecision(9) << (x + y) * sqrt(2) << endl;
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