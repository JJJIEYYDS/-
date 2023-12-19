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
ll g;
map<ll, ll> mp, mp1;
map<ll, priority_queue<PLL, vector<PLL>, greater<PLL>>> mp3;
map<ll, vector<PLL>> mp2;
void solve()
{
    cin >> g;

    for (int i = 1; i <= g; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x] += y;
    }

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            int x, y;
            cin >> x >> y;
            if (mp[x] >= y)
                continue;
            mp3[x].push({y, i});
            mp1[i]++;
        }
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int x, y;
            cin >> x >> y;
            mp2[i].push_back({x, y});
        }
    }
    priority_queue<ll> q;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp1.find(i) == mp1.end())
            q.push(i), ans++;
    }

    while (q.size())
    {
        int t = q.top();
        q.pop();
        for (auto [x, y] : mp2[t])
        {
            mp[x] += y;
            auto &p = mp3[x];
            while (p.size())
            {
                auto t1 = p.top();
                if (t1.first <= mp[x])
                {
                    mp1[t1.second]--;
                    p.pop();
                    if (mp1[t1.second] == 0)
                    {
                        q.push(t1.second);
                        ans++;
                    }
                }
                else
                    break;
            }
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