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

#define int long long

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef unsigned long long ULL;
typedef long long ll;
const int N = 1e7 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;

struct node
{
    ll l, r;
    ll sum;
    ll lazy;
    bool pd;
    ll d;
} tr[N * 4];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    if (!tr[u << 1].pd || !tr[u << 1 | 1].pd)
    {
        tr[u].pd = false;
    }
    else if (tr[u << 1].d != tr[u << 1 | 1].d)
    {
        tr[u].pd = false;
    }
    else
    {
        tr[u].pd = true;
        tr[u].d = tr[u << 1].d;
    }
}

void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    tr[u].lazy = -1;
    tr[u].sum = 0;

    if (l == r)
    {
        cin >> tr[u].sum;
        // cout << l << endl;
        tr[u].d = tr[u].sum;
        tr[u].pd = true;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}
void pushdown(int u)
{
    if (tr[u].lazy != -1)
    {
        tr[u << 1].d = tr[u].d;
        tr[u << 1 | 1].d = tr[u].d;

        tr[u << 1].sum = tr[u].lazy * (tr[u << 1].r - tr[u << 1].l + 1);
        tr[u << 1 | 1].sum = tr[u].lazy * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
        tr[u << 1].lazy = tr[u].lazy;
        tr[u << 1 | 1].lazy = tr[u].lazy;
        tr[u].lazy = -1;
    }
}
void modify1(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r && tr[u].pd)
    {
        cout << u << endl;
        ll ans = tr[u].d;
        ll c = 1;
        ll w = tr[u].d;
        while (1)
        {
            // cout << c << endl;
            ll d = w / (c * 10), z = w % c;
            ll res = d * c + z;
            ans = min(ans, res);
            c *= 10;
            if (d == 0)
                break;
        }
        // cout << 11111 << ' ' << ans << endl;
        tr[u].d = ans;
        tr[u].sum = (tr[u].r - tr[u].l + 1) * ans;
        tr[u].lazy = ans;
        return;
    }
    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid)
    {
        modify1(u << 1, l, r);
    }
    if (r > mid)
    {
        modify1(u << 1 | 1, l, r);
    }
    pushup(u);
}

void modify(int u, int l, int r, int x)
{
    if (tr[u].l >= l && tr[u].r <= r && tr[u].pd)
    {
        tr[u].d = x;
        tr[u].sum = (tr[u].r - tr[u].l + 1) * x;
        tr[u].lazy = x;
        return;
    }
    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid)
    {
        modify(u << 1, l, r, x);
    }
    if (r > mid)
    {
        modify(u << 1 | 1, l, r, x);
    }
    pushup(u);
}
ll query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        return tr[u].sum;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    ll sum1 = 0, sum2 = 0;
    if (l <= mid)
    {
        sum1 = query(u << 1, l, r);
    }
    if (r > mid)
    {
        sum2 = query(u << 1 | 1, l, r);
    }
    return sum1 + sum2;
}
void solve()
{
    cin >> n >> m;
    build(1, 1, n);
    while (m--)
    {
        int op;
        ll l, r, x;
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r;
            modify1(1, l, r);
        }
        else if (op == 2)
        {
            cin >> l >> r >> x;
            modify(1, l, r, x);
        }
        else
        {
            cin >> l >> r;
            cout << query(1, l, r) << endl;
        }
    }
}

signed main()
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