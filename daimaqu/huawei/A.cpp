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
const int N = 700, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
struct node
{
    ll a, b, d, e, f, g;
    double c;
    bool operator<(const node &p) const
    {
        if (f == p.f)
            return g < p.g;
        return f < p.f;
    }
} v[N];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d >> v[i].e >> v[i].f;
        v[i].g = i;
    }
    sort(v + 1, v + 1 + n);
    for (int i = 1; i <= m; i++)
    {
        int a, b, d, e, f;
        double c;
        cin >> a >> b >> c >> d >> e;
        for (int j = 1; j <= n; j++)
        {

            if (v[j].a >= a && v[j].b >= b && v[j].c >= c && v[j].d >= d && v[j].e >= e)
            {
                cout << v[j].g << endl;
                break;
            }
        }
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