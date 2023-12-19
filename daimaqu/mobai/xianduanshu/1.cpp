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

ll n, m, q;
ll a[N];

struct node
{
    ll l, r, sum;
    ll lazy;
} tr[4 * N];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u)
{
    tr[u << 1].sum += tr[u].lazy * (tr[u << 1].r - tr[u << 1].l + 1);
    tr[u << 1 | 1].sum += tr[u].lazy * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
    tr[u << 1].lazy += tr[u].lazy;
    tr[u << 1 | 1].lazy += tr[u].lazy;
    tr[u].lazy = 0;
}

void build(int u, int l, int r)
{
    tr[u].lazy = 0;
    tr[u].sum = 0;
    tr[u].l = l, tr[u].r = r;

    if (l == r)
    {
        tr[u].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int k)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum += k * (tr[u].r - tr[u].l + 1);
        tr[u].lazy += k;
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
    pushup(u);
    return sum1 + sum2;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);

    while (m--)
    {
        int op;
        ll x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            modify(1, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << query(1, x, y) << endl;
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