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
const int N = 4e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;
#define in long long
ll n, m, k, q;

vector<ll> v;

struct node
{
    int l, r;
    ll mx;
    ll lazy;
} tr[N * 4];

struct segment
{
    ll x, y1, y2, k;
    bool operator<(const segment &p) const
    {
        if (p.x == x)
        {
            return k > p.k;
        }

        return x < p.x;
    }
} seg[N * 4];

void pushup(int u)
{
    tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 0};
    // cout << u << ' ' << tr[u].l << ' ' << tr[u].r << endl;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void pushdown(int u)
{
    if (tr[u].lazy)
    {
        tr[u << 1].lazy += tr[u].lazy;
        tr[u << 1 | 1].lazy += tr[u].lazy;
        tr[u << 1 | 1].mx += tr[u].lazy;
        tr[u << 1].mx += tr[u].lazy;
        tr[u].lazy = 0;
    }
}
void modify(int u, int l, int r, ll k)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].mx += k;
        tr[u].lazy += k;
        pushdown(u);
        return;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid)
    {
        modify(u << 1, l, r, k);
    }
    if (r > mid)
    {
        modify(u << 1 | 1, l, r, k);
    }
    pushup(u);
}

ll find(ll x)
{
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void init()
{
    v.clear();
    memset(seg, 0, sizeof(seg));
    memset(tr, 0, sizeof(tr));
}
void solve()
{
    init();
    ll w, h;

    cin >> n >> w >> h;
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x, y, w1;
        cin >> x >> y;
        v.push_back(y);
        v.push_back(y + h - 1);

        seg[j++] = {x, y, y + h - 1, 1};
        seg[j++] = {x + w - 1, y, y + h - 1, -1};
    }

    sort(v.begin(), v.end());

    sort(seg, seg + 2 * n);
    build(1, 0, v.size() - 1);
    ll ans = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        ans = max(tr[1].mx, ans);
        modify(1, find(seg[i].y1), find(seg[i].y2), seg[i].k);
        // cout << tr[1].mx << ' ' << seg[i].k << endl;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    system("pause");
    return 0;
}