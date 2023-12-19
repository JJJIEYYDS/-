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
string s;
int a[N];
struct node
{
    int l, r;
    int l1, l2, r1, r2;
    int lazy;
    bool has;
} tr[N << 2];

void push_up(int u)
{
    if (tr[u << 1].has || tr[u << 1 | 1].has)
        tr[u].has = true;
    else
    {
        tr[u].has = 0;
    }
    if (tr[u << 1].r1 == tr[u << 1 | 1].l1)
    {
        tr[u].has = true;
    }
    if (tr[u << 1].r1 == tr[u << 1 | 1].l2)
    {
        tr[u].has = true;
    }
    if (tr[u << 1].r2 == tr[u << 1 | 1].l1)
    {
        tr[u].has = true;
    }
    if (tr[u << 1].l2 == -1)
    {
        tr[u].l2 = tr[u << 1 | 1].l1;
    }
    else
    {
        tr[u].l2 = tr[u << 1].l2;
    }
    if (tr[u << 1 | 1].r2 == -1)
    {
        tr[u].r2 = tr[u << 1].r1;
    }
    else
    {
        tr[u].r2 = tr[u << 1 | 1].r2;
    }
    tr[u].l1 = tr[u << 1].l1;
    tr[u].r1 = tr[u << 1 | 1].r1;
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, a[l], -1, a[r], -1, 0, false};
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void change(int u, int x)
{
    tr[u].l1 = (tr[u].l1 + x) % 26;
    tr[u].r1 = (tr[u].r1 + x) % 26;
    if (tr[u].l2 != -1)
    {
        tr[u].l2 = (tr[u].l2 + x) % 26;
    }
    if (tr[u].r2 != -1)
    {
        tr[u].r2 = (tr[u].r2 + x) % 26;
    }
    tr[u].lazy = (tr[u].lazy + x) % 26;
}
void push_down(int u)
{
    if (tr[u].lazy)
    {
        change(u << 1, tr[u].lazy);
        change(u << 1 | 1, tr[u].lazy);
    }
    tr[u].lazy = 0;
}

void modify(int u, int l, int r, int x)
{
    if (tr[u].r <= r && tr[u].l >= l)
    {
        change(u, x);
        return;
    }
    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid)
    {
        modify(u << 1, l, r, x);
    }
    if (r > mid)
    {
        modify(u << 1 | 1, l, r, x);
    }
    push_up(u);
}

node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        return tr[u];
    }
    push_down(u);
    node L, R, res;
    int mid = (tr[u].l + tr[u].r) >> 1;

    if (l <= mid)
    {
        L = query(u << 1, l, r);
    }
    if (r > mid)
    {
        R = query(u << 1 | 1, l, r);
    }

    if (l > mid)
    {
        return R;
    }
    else if (r <= mid)
    {
        return L;
    }
    else
    {
        if (L.has || R.has)
            res.has = true;
        else
        {
            res.has = 0;
        }
        if (L.r1 == R.l1)
        {
            res.has = true;
        }
        if (L.r1 == R.l2)
        {
            res.has = true;
        }
        if (L.r2 == R.l1)
        {
            res.has = true;
        }
        if (L.l2 == -1)
        {
            res.l2 = R.l1;
        }
        else
        {
            res.l2 = L.l2;
        }
        if (R.r2 == -1)
        {
            res.r2 = L.r1;
        }
        else
        {
            res.r2 = R.r2;
        }
        res.l1 = L.l1;
        res.r1 = R.r1;
        return res;
    }
}

void solve()
{
    cin >> n >> m;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - 'a';
    build(1, 1, n);

    while (m--)
    {
        int c, l, r, x;
        cin >> c >> l >> r;
        if (c == 1)
        {
            cin >> x;
            modify(1, l, r, x);
        }
        else
        {
            node t = query(1, l, r);
            cout << (t.has ? "No" : "Yes") << endl;
        }
    }
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