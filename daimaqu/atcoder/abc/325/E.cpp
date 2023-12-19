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
const int N = 1010, INF = 0x3f3f3f3f, mod = 998244353;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

ll n, m, k, q;
ll a, b, c;
vector<ll> dist1(N), dist2(N);
bool st[N];
ll g[N][N];

void dijkstra(vector<ll> &dist, ll t1, ll t2, ll t3)
{
    memset(st, 0, sizeof st);
    for (int i = 0; i < dist.size(); i++)
        dist[i] = INFL;
    dist[t1] = 0;
    priority_queue<PLL, vector<PLL>, greater<PLL>> heap; // 定义priority_queue和PII就是这样
    heap.push({0, t1});

    while (heap.size())
    {
        auto t = heap.top(); // 优先队列默认按照第一个dist来从小到大排序
        heap.pop();
        int ver = t.second;

        if (st[ver])
            continue; // 判断自环，重边，沉鱼
        st[ver] = true;

        for (int i = 1; i <= n; i++)
        {
            if (dist[i] > dist[ver] + g[ver][i] * t3 + t2)
            {
                dist[i] = dist[ver] + g[ver][i] * t3 + t2;
            }
            heap.push({dist[i], i});
        }
    }
}
void solve()
{
    cin >> n;
    cin >> a >> b >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    dijkstra(dist1, 1, 0, a), dijkstra(dist2, n, c, b);
    ll ans = min(dist1[n], dist2[1]);

    for (int i = 1; i <= n; i++)
    {
        ans = min(dist1[i] + dist2[i], ans);
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