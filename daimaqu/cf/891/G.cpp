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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q, s;

struct edges
{
    ll a, b, w;
    bool operator<(const edges &p) const
    {
        return w < p.w;
    }
};
ll p[N], si[N];

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}
ll qmi(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}
void solve()
{
    cin >> n >> s;
    vector<edges> e(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> e[i].a >> e[i].b >> e[i].w;
    }

    sort(e.begin(), e.end());

    for (int i = 1; i <= n; i++)
        p[i] = i, si[i] = 1;
    ll res = 1;

    for (auto [x, y, w] : e)
    {
        ll pa = find(x), pb = find(y);
        ll s1 = si[pa], s2 = si[pb];
        res = (res * (qmi(s - w + 1, s1 * s2 - 1))) % mod;
        if (pa == pb)
            continue;

        si[pb] += si[pa];
        p[pa] = pb;
    }
    cout << res << endl;
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