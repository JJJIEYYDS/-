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
    cin >> n >> m >> k;
    vector<ll> a(n + 1);
    vector<PLL> b(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i].first;

        b[i].second = i;
    }

    vector<vector<ll>> v(n + 1);
    for (int i = 1; i <= k; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[x].push_back(b[y].first);
    }
    ll ans = 0;
    sort(b.begin() + 1, b.end(), greater<PLL>());
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() == 0)
        {
            ans = max(ans, a[i] + b[1].first);
        }
        else
        {
            ll t1 = v[i].size();
            if (t1 >= m)
            {
                continue;
            }
            map<ll, ll> mp;
            for (int j = 1; j <= t1 + 1; j++)
            {
                mp[b[j].first]++;
            }
            for (auto x : v[i])
            {
                if (mp.find(x) != mp.end())
                {
                    if (mp[x] >= 2)
                    {
                        mp[x]--;
                    }
                    else
                        mp.erase(x);
                }
            }
            auto [x, y] = *(--mp.end());
            ans = max(ans, x + a[i]);
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