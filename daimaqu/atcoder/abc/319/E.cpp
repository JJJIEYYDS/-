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
ll x, y;

void solve()
{
    cin >> n >> x >> y;
    vector<PLL> a(n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    vector<ll> dp(1000);
    for (int i = 0; i < 840; i++) // 840倍数时间之后，一摸一样，只需处理出发时间在0~839之中就行
    {
        ll cur = i;
        for (auto [p, t] : a)
        {
            ll w = (p - cur % p) % p;
            cur = cur + w + t;
        }
        dp[i] = cur - i;
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        ll t;
        cin >> t;
        cout << t + x + dp[(t + x) % 840] + y << endl;
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