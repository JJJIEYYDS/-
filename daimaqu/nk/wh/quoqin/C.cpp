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
ll a[5], b[5], c[5], d[5];
ll xj(int u, int v)
{
    if (min(c[u], c[v]) - max(a[u], a[v]) > 0 && min(d[u], d[v]) - max(b[u], b[v]) > 0)
        return (min(c[u], c[v]) - max(a[u], a[v])) * (min(d[u], d[v]) - max(b[u], b[v]));
    else
        return 0;
}
ll xj1(int u, int v, int w)
{
    if ((min(c[1], min(c[2], c[3])) - max(a[1], max(a[2], a[3]))) > 0 && (min(d[1], min(d[2], d[3])) - max(b[1], max(b[2], b[3]))) > 0)
        return (min(c[1], min(c[2], c[3])) - max(a[1], max(a[2], a[3]))) * (min(d[1], min(d[2], d[3])) - max(b[1], max(b[2], b[3])));
    else
        return 0;
}
void solve()
{

    ll ans = 0;
    for (int i = 1; i <= 3; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        ans += (abs(a[i] - c[i]) * abs(b[i] - d[i]));
    }
    ans -= xj(1, 2);

    ans -= xj(1, 3);

    ans -= xj(2, 3);
    ans += xj1(1, 2, 3);
    cout << ans << endl;
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