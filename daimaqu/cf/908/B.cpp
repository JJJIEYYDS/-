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
    vector<ll> a(n + 1);
    map<ll, vector<ll>> mp;
    vector<ll> ans(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    ll t = 0, maxx = 0;
    for (auto [x, y] : mp)
    {
        if (y.size() >= 2)
        {
            t++;
            maxx = max(maxx, (ll)y.size());
        }
    }
    if (t >= 3)
    {
        ll t1 = 2;
        for (auto [x, y] : mp)
        {
            if (y.size() == 1)
            {
                ans[y[0]] = 1;
            }
            else if (y.size() >= 2)
            {
                if (t1 < 4)
                {
                    ans[y[0]] = t1++;
                    for (int i = 1; i < y.size(); i++)
                    {
                        ans[y[i]] = 1;
                    }
                }
                else
                {
                    for (int i = 0; i < y.size(); i++)
                    {
                        ans[y[i]] = 1;
                    }
                }
            }
        }
    }
    else if (t == 2)
    {
        if (maxx >= 2)
        {
            ll t1 = 2;
            for (auto [x, y] : mp)
            {
                if (y.size() == 1)
                {
                    ans[y[0]] = 1;
                }
                else if (y.size() >= 2)
                {
                    ans[y[0]] = t1++;
                    for (int i = 1; i < y.size(); i++)
                    {
                        ans[y[i]] = 1;
                    }
                }
            }
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    else
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
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