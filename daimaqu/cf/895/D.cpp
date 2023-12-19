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
    ll x, y;
    cin >> n >> x >> y;
    ll cnt1 = n / x, cnt2 = n / y;
    ll t = (x * y) / __gcd(x, y);
    ll cnt3 = n / t;
    ll ans = 0;
    ans = ans + n * (cnt1 - cnt3) - (cnt1 - cnt3 - 1) * (cnt1 - cnt3) / 2;
    ans = ans - (cnt2 - cnt3) * (cnt2 - cnt3 + 1) / 2;
    cout << ans << endl;
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