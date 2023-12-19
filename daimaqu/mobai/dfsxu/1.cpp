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
const ll N = 5e5 + 10, INF = 2e9, mod = 998244353;

ll n, m, k, q;
#define int ll

vector<vector<ll>> edges;

struct node
{
    ll l, r;
    ll lazy;
    ll sum;
} tr[N * 4];

struct tt
{
    ll a, b, c;
} p[N];

ll L[N], R[N];
ll pos = 0;

void dfs(int u, int fa)
{
    L[u] = ++pos;
    for (auto v : edges[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
    }
    R[u] = pos;
}

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    tr[u].lazy = 0;
    tr[u].sum = 0;
    if (l == r)
    {
        return;
    }
    ll mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void pushdown(int u)
{
    tr[u << 1].sum += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].lazy;
    tr[u << 1 | 1].sum += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].lazy;
    tr[u << 1].lazy += tr[u].lazy;
    tr[u << 1 | 1].lazy += tr[u].lazy;
    tr[u].lazy = 0;
}
void modify(int u, int l, int r, ll w)
{
    // cout << u << ' ' << tr[u].l << ' ' << tr[u].r << endl;
    if (tr[u].l >= l && tr[u].r <= r)
    {
        if (w == -INF)
        {
            tr[u].lazy = 0;
            tr[u].sum = 0;
            return;
        }
        else
        {
            tr[u].lazy += w;
            tr[u].sum += (tr[u].r - tr[u].l + 1) * w;
            return;
        }
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid)
    {
        modify(u << 1, l, r, w);
    }
    if (r > mid)
    {
        modify(u << 1 | 1, l, r, w);
    }
    pushup(u);
}

ll query(int u, int l)
{
    if (tr[u].l >= l && tr[u].r <= l)
    {
        return tr[u].sum;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    ll sum1 = 0, sum2 = 0;
    if (l <= mid)
    {
        sum1 = query(u << 1, l);
    }
    else
    {
        sum2 = query(u << 1 | 1, l);
    }
    // pushup(u);
    return sum1 + sum2;
}

void solve()
{
    cin >> q;
    ll cnt = 1;
    edges = vector<vector<ll>>(q + 100);

    pos = 0;
    for (int i = 1; i <= q; i++)
    {
        ll op, x, w;
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            edges[x].push_back(++cnt);
            edges[cnt].push_back(x);

            p[i] = {op, cnt, -INF};
        }
        else
        {
            cin >> x >> w;
            p[i] = {op, x, w};
        }
    }
    dfs(1, 0);
    build(1, 1, cnt);

    for (int i = 1; i <= q; i++)
    {
        auto [a, b, c] = p[i];
        modify(1, L[b], R[b], c);
    }

    for (int i = 1; i <= cnt; i++)
    {
        cout << query(1, L[i]) << ' ';
        }

    cout << '\n';
}

signed main()
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