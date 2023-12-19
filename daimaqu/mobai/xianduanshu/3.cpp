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

struct node
{
    ll l, r;
    ll lval, rval;
    ll lazy;
    ll sum;
} tr[N << 2];

void pushup(int u)
{
    if (tr[u << 1 | 1].sum == tr[u].lval)
    {
        tr[u].sum = tr[u << 1].sum;
    }
    else
        tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].sum = abs(tr[u << 1].rval - tr[u << 1 | 1].lval);
    tr[u].lval = tr[u << 1].lval;
    tr[u].rval = tr[u << 1 | 1].rval;
}

void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    tr[u].sum = 0;
    tr[u].lazy = 0;
    if (l == r)
    {
        cin >> tr[l].sum;
        tr[l].lval = tr[l].sum;
        tr[l].rval = tr[l].sum;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void pushdown(int u)
{
    tr[u << 1 | 1].lazy += tr[u].lazy;
    tr[u << 1].lazy += tr[u].lazy;
    tr[u << 1].sum += tr[u].lazy;
    tr[u << 1 | 1].sum += tr[u].lazy;
    tr[u << 1].lval += tr[u].lazy;
    tr[u << 1].rval += tr[u].lazy;
    tr[u << 1 | 1].lval += tr[u].lazy;
    tr[u << 1 | 1].rval += tr[u].lazy;
    tr[u].lazy = 0;
}

void modify(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum += 1;
        tr[u].lval += 1;
        tr[u].rval += 1;
        tr[u].lazy += 1;
        return;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid)
    {
        modify(u << 1, l, r);
    }
    if (r > mid)
    {
        modify(u << 1 | 1, l, r);
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
    bool flag1 = false, flag2 = false;
    if (l <= mid)
    {
        flag1 = true;
        sum1 = query(u << 1, l, r);
    }
    else if (mid > r)
    {
        flag2 = true;
        sum2 = query(u << 1 | 1, l, r);
    }
    pushup(u);
    if (flag1 && !flag2)
    {
        return sum1;
    }
    else if (!flag1 && flag2)
    {
        return sum2;
    }
    else
    {
        ll res = sum1 + sum2 - tr[u << 1 | 1].lval + abs(tr[u << 1].rval - tr[u << 1 | 1].lval);
        return res;
    }
}
void solve()
{
    cin >> n >> q;
    build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        ll op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            cout << query(1, l, r) << endl;
        }
        else
        {
            modify(1, l, r);
        }
    }
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