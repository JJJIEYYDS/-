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
    map<ll, ll> mp;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        mp[x] += y;
    }
    ll ans = 0;
    for (auto [x, y] : mp)
    {
        if (y % 2 == 0)
        {
            mp[x * 2] += y / 2;
        }
        else
        {
            if (y == 1)
            {
                ans++;
                continue;
            }
            mp[x * 2] += y / 2;
            ans++;
        }
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