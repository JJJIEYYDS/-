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
vector<vector<ll>> v;
ll ans = 1e18;
ll t1 = 1e18;
ll dfs(ll u, int fa)
{
    ll sum = 1, res = 0;
    for (auto x : v[u])
    {
        if (x == fa)
            continue;
        ll j = dfs(x, u);
        sum += j;
        res = max(res, j);
    }
    res = max(res, n - sum);
    if (res < ans)
    {
        ans = res;
        t1 = u;
    }
    else if (res == ans)
    {
        t1 = min(t1, u);
    }
    // cout << 111 << ' ' << u << ' ' << sum << ' ' << res << endl;
    return sum;
}
void solve()
{
    cin >> n;

    v = vector<vector<ll>>(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, 0);
    cout << t1 << endl;
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