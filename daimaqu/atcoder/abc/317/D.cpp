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
ll v[N], w[N];
int cnt = 1;
ll dp[N];

void solve()
{
    cin >> n;
    ll cnt1 = 0, cnt2 = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int u1, v1, w1;
        cin >> u1 >> v1 >> w1;
        sum += w1;
        if (u1 > v1)
            cnt1 += w1, w[cnt] = 0, v[cnt++] = w1;
        else if (u1 < v1)
            cnt2 += w1, w[cnt] = (u1 + v1 + 1) / 2 - u1, v[cnt++] = w1;
    }
    if (cnt1 > cnt2)
    {
        cout << 0 << endl;
        return;
    }
    m = sum;
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    ll ans = 1e18;
    for (int i = (sum + 1) / 2; i <= sum; i++)
    {
        ans = min(ans, dp[i]);
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