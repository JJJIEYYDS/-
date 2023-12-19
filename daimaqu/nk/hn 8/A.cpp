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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q, w;
ll p[N], s[N];
bool st1[N];

ll find(ll x)
{
    if (x != p[x])
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
void solve()
{
    cin >> n >> m >> k >> w;
    vector<ll> a(n + 1), b(n + 1), c;
    set<ll> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (b[i] == 1)
            st.insert(i), c.push_back(i);
    }
    for (int i = 1; i <= n; i++)
        p[i] = i, s[i] = a[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (st.find(u) != st.end() && st.find(v) != st.end())
        {
            ll pa = find(u), pb = find(v);
            if (pa != pb)
            {
                p[pa] = pb;
                s[pb] += s[pa];
            }
        }
    }
    vector<ll> e;
    for (int i = 0; i < c.size(); i++)
    {
        ll pa = find(c[i]);
        if (!st1[pa])
        {
            st1[pa] = true;
            e.push_back(s[pa]);
        }
    }
    sort(e.begin(), e.end(), greater<ll>());
    ll ans = 0;
    for (int i = 0; i < min((ll)e.size(), k); i++)
    {
        ans += e[i];
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