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
typedef unsigned long long ULL;
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;

void solve()
{
    cin >> n;

    vector<ll> a(n + 1);
    map<ll, ll> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    sort(a.begin() + 1, a.end());
    vector<ll> b;
    for (int i = 1; i < n; i++)
    {
        b.push_back(a[i + 1] - a[i]);
    }
    ll res = b[0];
    for (int i = 1; i < b.size(); i++)
    {
        res = __gcd(res, b[i]);
    }
    ll ans = 1e18;
    ll res1 = 0;
    res = max(res, 1ll);
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        res1 += (a[n] - a[i]) / res;
    }
    // cout << res1 << endl;
    ans = res1 + n;

    for (int i = 1; i <= n + 100; i++)
    {
        if (mp.find(a[n] - res * i) == mp.end())
        {
            ans = min(ans, res1 + i);
            break;
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
    cin >> t;

    while (t--)
        solve();

    system("pause");
    return 0;
}