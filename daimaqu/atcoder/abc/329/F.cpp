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
#define endl '\n'

ll n, m, k, q;

void solve()
{
    cin >> n >> q;
    map<ll, set<ll>> mp;

    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        mp[i].insert(x);
    }
    for (int i = 1; i <= q; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (mp[a].size() >= 1)
        {
            // cout << 111 << endl;
            if (mp[a].size() <= mp[b].size())
            {
                // cout << 1 << endl;
                for (auto x : mp[a])
                {
                    if (mp[b].find(x) == mp[b].end())
                    {
                        mp[b].insert(x);
                    }
                }
            }
            else
            {
                // cout << 1111111 << endl;
                for (auto x : mp[b])
                {
                    if (mp[a].find(x) == mp[a].end())
                    {
                        mp[a].insert(x);
                    }
                }
                swap(mp[a], mp[b]);
            }
        }
        else
        {
        }
        mp[a].clear();
        cout << mp[b].size() << endl;
    }
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