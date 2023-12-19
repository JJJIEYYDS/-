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
int p[N], s[N];

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    // 只有两条不同路，用并查集维护一条，剩下默认另一条
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i, s[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int pa = find(a), pb = find(b);
        if (pa == pb || c != 2)
            continue;
        s[pb] += s[pa];
        p[pa] = pb;
    }
    ll ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, (s[find(i)] - 1) * 2 + (n - s[find(i)]));
    }
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