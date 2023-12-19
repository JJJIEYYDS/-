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
ll p[N], d[N];
ll find(ll x)
{
    if (x != p[x])
    {
        ll t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        d[i] = 0;
    }
    vector<ll> ans;
    for (int i = 1; i <= m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll pa = find(a), pb = find(b);
        if (pa != pb)
        {
            p[pa] = pb;
            d[pa] = c + d[b] - d[a];
            ans.push_back(i);
        }
        else
        {
            if (d[a] - d[b] == c)
            {
                ans.push_back(i);
            }
        }
    }
    for (auto x : ans)
    {
        cout << x << ' ';
    }
    cout << endl;
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