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
struct node
{
    ll l, r;
    bool operator<(const node &p) const
    {
        if (l == p.l)
        {
            return r < p.r;
        }
        return l < p.l;
    }
} se[N];
void solve()
{
    cin >> n;
    memset(se, 0, sizeof 0);
    for (int i = 1; i <= n; i++)
    {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        se[i].l = l, se[i].r = b;
    }

    sort(se + 1, se + n + 1);
    vector<PLL> a;
    for (int i = 1; i < n; i++)
    {
        if (se[i + 1].l > se[i].r)
        {
            a.push_back({se[i].l, se[i].r});
            continue;
        }
        se[i + 1].l = se[i].l, se[i + 1].r = max(se[i + 1].r, se[i].r);
    }
    a.push_back({se[n].l, se[n].r});

    cin >> q;
    vector<PLL> v(q + 1);
    vector<ll> ans(q + 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> v[i].first, v[i].second = i;
        ans[i] = v[i].first;
    }
    n = a.size();
    sort(v.begin() + 1, v.end());
    for (int i = 1, j = 0; i <= q; i++)
    {
        while (j < n && a[j].first <= v[i].first)
        {
            j++;
        }
        if (j != 0)
            j--;
        if (a[j].second >= v[i].first && a[j].first <= v[i].first)
            ans[v[i].second] = max(a[j].second, ans[v[i].second]);
    }

    for (int i = 1; i <= q; i++)
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