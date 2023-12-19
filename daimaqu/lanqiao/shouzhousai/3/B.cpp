#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <array>

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
    for (int i = 1; i <= n; i++)
    {
        ll a, res = 2001;
        cin >> a;
        if (a == 1111)
        {
            res = 0;
        }
        res = min(res, a);
        if (a >= 500)
            res = min(res, a - a / 10);
        if (a >= 1000)
        {
            res = min(res, a - 150);
        }
        res = min(res, a - a / 20);
        ans += res;
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