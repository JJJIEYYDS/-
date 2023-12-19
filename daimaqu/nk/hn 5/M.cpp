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

ll n, m, k, q, top;

struct Point
{
    double x, y;
} p[N], s[N];
double cross(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dis(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool cmp(Point a, Point b)
{
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}
void Andrew()
{
    sort(p + 1, p + n + 1, cmp);
    top = 0;
    for (int i = 1; i <= n; i++) // 下凸包
    {
        while (top > 1 && cross(s[top - 1], s[top], p[i]) <= 0)
            top--;
        s[++top] = p[i];
    }
    int t = top;
    for (int i = n - 1; i >= 1; i--)
    {
        while (top > t && cross(s[top - 1], s[top], p[i]) <= 0)
            top--;
        s[++top] = p[i];
    }

    n = top - 1;
}
void rotating()
{
    double res = 1e18;
    for (int i = 1, j = 2; i <= n; i++)
    {
        while (cross(s[i], s[i + 1], s[j]) < cross(s[i], s[i + 1], s[j + 1]))
        {
            j = j % n + 1;
        } // 旋转卡壳不需要变
        // 只需变值就够
        res = min(res, abs(cross(s[i], s[i + 1], s[j]) / dis(s[i], s[i + 1])));
    }

    cout << fixed << setprecision(2) << res << endl;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    Andrew();

    rotating();
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