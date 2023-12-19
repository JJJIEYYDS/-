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
    double px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    bool flaga1 = false, flaga2 = false;
    bool flagb1 = false, flagb2 = false;
    if (sqrt((px - ax) * (px - ax) + (py - ay) * (py - ay)) >= sqrt((px - bx) * (px - bx) + (py - by) * (py - by)))
    {
        flaga1 = true;
    }
    else
        flagb1 = true;
    if (sqrt((ax * ax) + ay * ay) >= sqrt(bx * bx + by * by))
    {
        flaga2 = true;
    }
    else
    {
        flagb2 = true;
    }
    if ((flaga1 && flaga2) || (flagb1 && flagb2))
    {

        if (flaga1 && flaga2)
        {
            double ans = max(sqrt((px - bx) * (px - bx) + (py - by) * (py - by)), sqrt((bx * bx) + by * by));
            cout << fixed << setprecision(10) << ans << endl;
        }
        else
        {
            double ans = max(sqrt((px - ax) * (px - ax) + (py - ay) * (py - ay)), sqrt((ax * ax) + ay * ay));
            cout << fixed << setprecision(10) << ans << endl;
        }
    }
    else
    {
        double ans = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
        ans /= 2;
        if (flaga1)
        {
            ans = max(ans, sqrt((px - bx) * (px - bx) + (py - by) * (py - by)));
            ans = max(ans, sqrt((ax * ax) + ay * ay));
        }
        else if (flaga2)
        {
            ans = max(ans, sqrt((px - ax) * (px - ax) + (py - ay) * (py - ay)));
            ans = max(ans, sqrt(bx * bx + by * by));
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
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