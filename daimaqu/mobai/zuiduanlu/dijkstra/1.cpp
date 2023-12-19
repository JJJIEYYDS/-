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
vector<PLL> edges[N];
ll dis[N];
bool st[N];

void dijkstra()
{
    memset(dis, 0x3f, sizeof dis);

    set<ll> s;
    for (int i = 2; i <= n; i++)
    {
        s.insert(i);
    }
    priority_queue<PLL, vector<PLL>, greater<PLL>> p;
    dis[1] = 0;
    p.push({0, 1});
    while (p.size())
    {
        auto t = p.top();
        p.pop();
        if (st[t.second])
            continue;
        st[t.second] = true;
        set<ll> te;
        for (auto [x, y] : edges[t.second])
        {
            te.insert(x);
            if (dis[x] > dis[t.second] + y)
            {
                dis[x] = dis[t.second] + y;
                p.push({dis[x], x});
            }
        }
        vector<ll> res;

        for (auto x : s)
        {
            if (!te.count(x))
            {
                res.push_back(x);
                if (dis[x] > dis[t.second] + k)
                {
                    dis[x] = dis[t.second] + k;
                    p.push({dis[x], x});
                }
            }
        }
        for (auto x : res)
        {
            s.erase(x);
        }
    }
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    dijkstra();
    cout << dis[n] << endl;
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