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

ll n, m, k, q;

void solve()
{
    cin >> n >> q;
    vector<ll> a(n + 1), b(q + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> mp, mp1;
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        mp[pow(2, x)]++;
        b[i] = x;
    }
    ll t1 = 55, t2 = -1;
    for (int i = 1; i <= q; i++)
    {
        if (b[i] < t1)
        {
            t1 = b[i];
            t2 = i;
        }
        if (mp1.find(pow(2, b[i])) == mp1.end())
        {
            if (t2 == i)
            {
                mp1[pow(2, b[i])] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ll ans = a[i];
        if (mp.find(a[i]) != mp.end())
        {
        }
        for (auto [x, y] : mp)
        {
            if (mp1.find(x) == mp1.end())
                continue;
            if (a[i] % x == 0)
            {
                ans += x / 2;
            }
        }
        cout << ans << ' ';
    }
    cout << endl;
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