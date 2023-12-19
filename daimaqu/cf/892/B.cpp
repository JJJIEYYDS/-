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
    cin >> n;
    ll ans = 0;
    ll cnt1 = 1e18, cnt2 = 1e18;

    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        vector<ll> a(m + 1);
        for (int j = 1; j <= m; j++)
        {
            cin >> a[j];
        }
        sort(a.begin() + 1, a.end());
        ans += a[2];
        cnt1 = min(cnt1, a[1]);
        cnt2 = min(cnt2, a[2]);
    }
    cout << ans - cnt2 + cnt1 << endl;
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