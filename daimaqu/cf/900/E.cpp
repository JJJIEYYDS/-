#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <bitset>

using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
vector<array<ll, 40>> a(N);
bool check(ll l, ll mid, ll t)
{
    ll res = 0;
    for (int i = 0; i < 32; i++)
    {
        if (a[mid][i] - a[l - 1][i] == mid - l + 1)
        {
            res += (1ll << i);
        }
    }
    return res >= t;
}
void solve()
{
    cin >> n;

    vector<ll> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        b[i] = x;
        bitset<32> b(x);
        for (int j = 0; j < 32; j++)
        {
            a[i][j] = a[i - 1][j] + (b[j] == 1);
        }
    }

    cin >> m;
    vector<PLL> v(m + 1);
    map<PLL, ll> mp, mp1;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (b[x] < y)
        {
            v[i] = {-1, -1};
            continue;
        }
        v[i] = {x, y};
        mp[{x, y}] = y;
    }
    for (auto [x, y] : mp)
    {
        ll l = x.first, r = n;
        while (l < r)
        {
            ll mid = (l + r + 1) >> 1;
            if (check(x.first, mid, y))
            {
                l = mid;
            }
            else
                r = mid - 1;
        }
        mp1[{x.first, x.second}] = l;
    }

    for (int i = 1; i <= m; i++)
    {
        if (v[i].first != -1)
            cout << mp1[v[i]] << ' ';
        else
            cout << -1 << ' ';
    }
    cout << endl;
    a.clear();
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