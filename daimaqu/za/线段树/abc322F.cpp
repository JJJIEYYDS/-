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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
string s;
struct node
{
    int l, r;
    int lazy;
    int num_1, num_0;
    int l1, l0, r1, r0;
    int pd1, pd0;
} tr[N << 2];

void push_up(int u)
{
    int t = tr[u << 1].r1 + tr[u << 1 | 1].l1;
    tr[u].num_1 = max(tr[u << 1].num_1, tr[u << 1 | 1].num_1);
    tr[u].num_1 = max(tr[u].num_1, max(tr[u << 1].l1, tr[u << 1 | 1].r1));
    tr[u].num_1 = max(t, tr[u].num_1);
    if (tr[u << 1].pd1)
    {
        tr[u].l1 = tr[u << 1].l1 + tr[u << 1 | 1].l1;
    }
    else
        tr[u].l1 = tr[u << 1].l1;
    if (tr[u << 1 | 1].pd1)
    {
        tr[u].r1 = tr[u << 1].r1 + tr[u << 1 | 1].r1;
    }
    else
        tr[u].r1 = tr[u << 1 | 1].r1;
    if (tr[u << 1].pd1 && tr[u << 1 | 1].pd1)
    {
        tr[u].pd1 = 1;
    }
    else
    {
        tr[u].pd1 = 0;
    }
    t = tr[u << 1].r0 + tr[u << 1 | 1].l0;
    tr[u].num_0 = max(tr[u << 1].num_0, tr[u << 1 | 1].num_0);
    tr[u].num_0 = max(tr[u].num_0, max(tr[u << 1].l0, tr[u << 1 | 1].r0));
    tr[u].num_0 = max(t, tr[u].num_0);
    if (tr[u << 1].pd0)
    {
        tr[u].l0 = tr[u << 1].l0 + tr[u << 1 | 1].l0;
    }
    else
        tr[u].l0 = tr[u << 1].l0;
    if (tr[u << 1 | 1].pd0)
    {
        tr[u].r0 = tr[u << 1].r0 + tr[u << 1 | 1].r0;
    }
    else
        tr[u].r0 = tr[u << 1 | 1].r0;
    if (tr[u << 1].pd0 && tr[u << 1 | 1].pd0)
    {
        tr[u].pd0 = 1;
    }
    else
    {
        tr[u].pd0 = 0;
    }
}
void build(int u, int l, int r)
{
    if (l == r)
    {
        tr[u].l = tr[u].r = l;
        tr[u].lazy = 0;
        if (s[l] == '1')
        {
            tr[u].pd1 = 1, tr[u].pd0 = 0;
            tr[u].num_1 = 1, tr[u].num_0 = 0;
            tr[u].l1 = 1, tr[u].l0 = 0, tr[u].r1 = 1, tr[u].r0 = 0;
        }
        else
        {
            tr[u].pd1 = 0, tr[u].pd0 = 1;
            tr[u].num_1 = 0, tr[u].num_0 = 1;
            tr[u].l1 = 0, tr[u].l0 = 1, tr[u].r1 = 0, tr[u].r0 = 1;
        }
        return;
    }
    tr[u].l = l, tr[u].r = r;
    tr[u].lazy = 0;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}
void swap(int u)
{
    swap(tr[u].pd1, tr[u].pd0);
    swap(tr[u].num_1, tr[u].num_0);
    swap(tr[u].l1, tr[u].l0);
    swap(tr[u].r0, tr[u].r1);
}

void push_down(int u)
{
    if (tr[u].lazy == 0)
    {
        return;
    }
    tr[u << 1].lazy ^= 1;
    tr[u << 1 | 1].lazy ^= 1;
    swap(u << 1);
    swap(u << 1 | 1);
    tr[u].lazy = 0;
}
void modify(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].lazy ^= 1;
        swap(u);
        return;
    }
    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid)
    {
        modify(u << 1, l, r);
    }
    if (r > mid)
    {
        modify(u << 1 | 1, l, r);
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
    int mid = (tr[u].l + tr[u].r) >> 1;
    node L, R;
    if (l <= mid)
    {
        L = query(u << 1, l, r);
    }
    if (r > mid)
    {
        R = query(u << 1 | 1, l, r);
    }
    push_up(u);

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
        node res;
        int z = L.r1 + R.l1;
        res.num_1 = std::max(L.l1, R.r1);
        res.num_1 = std::max(res.num_1, z);
        res.num_1 = std::max(res.num_1, std::max(L.num_1, R.num_1));
        if (L.pd1)
        {
            res.l1 = L.l1 + R.l1;
        }
        else
        {
            res.l1 = L.l1;
        }
        if (R.pd1)
        {
            res.r1 = R.r1 + L.r1;
        }
        else
        {
            res.r1 = R.r1;
        }
        if (L.pd1 && R.pd1)
        {
            res.pd1 = 1;
        }
        else
        {
            res.pd1 = 0;
        }
        return res;
    }
}

void query1(int u)
{
    if (tr[u].l == tr[u].r)
    {
        cout << tr[u].num_1 << " ";
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    query1(u << 1);
    query1(u << 1 | 1);
}

void solve()
{
    cin >> n >> q;
    cin >> s;
    s = ' ' + s;
    build(1, 1, n);
    // query1(1);
    while (q--)
    {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1)
        {
            modify(1, l, r);
        }
        else
        {
            node p = query(1, l, r);
            cout << p.num_1 << endl;
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