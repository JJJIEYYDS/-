
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <cmath>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>

const int N = 2e5 + 10;

std::string s;
int a[N];
int n, m;

struct Node
{
    int l, r;
    int l1, l2, r1, r2;
    int add;
    bool has;
} tr[N << 2];

struct SegTree
{
    void pushup(Node &rt, Node &lh, Node &rh)
    {
        rt.has = std::max(lh.has, rh.has);
        if (lh.r1 != -1 && (lh.r1 == rh.l1 || lh.r1 == rh.l2))
            rt.has = true;
        if (lh.r2 != -1 && lh.r2 == rh.l1)
            rt.has = true;
        rt.l1 = lh.l1, rt.r1 = rh.r1;
        if (lh.l2 == -1)
            rt.l2 = rh.l1;
        else
            rt.l2 = lh.l2;
        if (rh.r2 == -1)
            rt.r2 = lh.r1;
        else
            rt.r2 = rh.r2;
    }
    void pushup(int u)
    {
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void change(int u, int add)
    {
        tr[u].l1 = (tr[u].l1 + add) % 26;
        if (tr[u].l2 != -1)
            tr[u].l2 = (tr[u].l2 + add) % 26;
        tr[u].r1 = (tr[u].r1 + add) % 26;
        if (tr[u].r2 != -1)
            tr[u].r2 = (tr[u].r2 + add) % 26;
        tr[u].add = (tr[u].add + add) % 26;
    }

    void pushdown(int u)
    {
        if (tr[u].add)
        {
            change(u << 1, tr[u].add);
            change(u << 1 | 1, tr[u].add);
        }
        tr[u].add = 0;
    }

    void build(int u, int l, int r)
    {
        tr[u] = {l, r, a[l], -1, a[r], -1, 0, false};
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int l, int r, int add)
    {
        if (l <= tr[u].l && tr[u].r <= r)
        {
            change(u, add);
            return;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid)
            modify(u << 1, l, r, add);
        if (r > mid)
            modify(u << 1 | 1, l, r, add);
        pushup(u);
    }

    Node query(int u, int l, int r)
    {
        if (l <= tr[u].l && tr[u].r <= r)
            return tr[u];

        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;

        Node left, right, res;
        if (l <= mid)
            left = query(u << 1, l, r);
        if (r > mid)
            right = query(u << 1 | 1, l, r);

        if (l <= mid && r <= mid)
            return left;
        if (l > mid && r > mid)
            return right;
        pushup(res, left, right);
        return res;
    }
} T;

void solve()
{
    std::cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - 'a';

    T.build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op, l, r, x;
        std::cin >> op >> l >> r;

        if (op == 1)
        {
            std::cin >> x;
            T.modify(1, l, r, x);
        }
        else
        {
            auto res = T.query(1, l, r);
            if (res.has)
                std::cout << "NO\n";
            else
                std::cout << "YES\n";
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
    return 0;
}
