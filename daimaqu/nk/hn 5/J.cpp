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
bool st[N];
ll ans = 0;
void bfs(vector<vector<int>> v, vector<int> a)
{
    queue<PLL> p;
    p.push({1, 1});
    st[1] = true;
    int cnt = 1;

    while (p.size())
    {
        auto t = p.front();
        p.pop();
        ans += (t.second * a[cnt]);
        cnt++;
        for (auto x : v[t.first])
        {
            if (!st[x])
                p.push({x, t.second + 1}), st[x] = true;
        }
    }

    cout << ans << endl;
}

void solve()
{
    cin >> n;
    ans = 0;
    vector<vector<int>> v(n + 1);
    vector<int> a(n + 1);
    memset(st, 0, sizeof st);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    bfs(v, a);
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