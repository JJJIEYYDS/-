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
    vector<ll> v(n + 1);
    map<ll, vector<ll>> mp;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        mp[i - x].push_back(x);
    }
    ll ans = 0;
    for (auto [x, v] : mp)
    {
        sort(v.begin(), v.end(), greater<ll>());
        if (v.size() % 2 == 0)
        {
            ll t = 0, cnt = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (i % 2 == 0)
                {
                    t += v[i];
                }
                else
                {
                    t += v[i];
                    ans = max(ans, ans + t);
                    t = 0;
                }
            }
        }
        else
        {
            v.pop_back();
            ll t = 0, cnt = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (i % 2 == 0)
                {
                    t += v[i];
                }
                else
                {
                    t += v[i];
                    ans = max(ans, ans + t);
                    t = 0;
                }
            }
        }
    }
    ans = max(ans, (ll)0);
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