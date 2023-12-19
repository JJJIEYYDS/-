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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
const int mod1 = 805306457, mod2 = 1610612741;

ll n, m, k, q;

string s;
ll p1[N], p2[N];

struct node
{
    int l, r;
    ULL z1, z2, f1, f2;
} tr[N * 4];

void init()
{
    p1[0] = 1, p2[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        p1[i] = p1[i - 1] * 131 % mod1;
        p2[i] = p2[i - 1] * 131 % mod2;
    }
}

void pushup(node &res, node &sum1, node &sum2)
{
    res.z1 = (sum1.z1 * p1[sum2.r - sum2.l + 1] % mod1 + sum2.z1) % mod1;
    res.z2 = (sum1.z2 * p2[sum2.r - sum2.l + 1] % mod2 + sum2.z2) % mod2;
    res.f1 = (sum2.f1 * p1[sum1.r - sum1.l + 1] % mod1 + sum1.f1) % mod1;
    res.f2 = (sum2.f2 * p2[sum1.r - sum1.l + 1] % mod2 + sum1.f2) % mod2;
    res.l = sum1.l;
    res.r = sum2.r;
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    if (l == r)
    {
        tr[u].z1 = s[l];
        tr[u].f1 = s[l];
        tr[u].z2 = s[l];
        tr[u].f2 = s[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, char c)
{
    if (tr[u].l >= x && tr[u].r <= x)
    {
        tr[u].z1 = c;
        tr[u].f1 = c;
        tr[u].z2 = c;
        tr[u].f2 = c;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (x <= mid)
    {
        modify(u << 1, x, c);
    }
    else
        modify(u << 1 | 1, x, c);
    pushup(u);
}

node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        return tr[u];
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    node res, sum1, sum2;
    if (r <= mid)
    {
        return query(u << 1, l, r);
    }
    if (l > mid)
    {
        return query(u << 1 | 1, l, r);
    }
    sum1 = query(u << 1, l, r);
    sum2 = query(u << 1 | 1, l, r);
    pushup(res, sum1, sum2);
    return res;
}
void solve()
{
    cin >> n >> q;
    cin >> s;
    s = ' ' + s;
    build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            char c;
            cin >> x >> c;
            modify(1, x, c);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            node res = query(1, l, r);
            if ((res.z1 == res.f1) && (res.z2 == res.f2))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t = 1;
    // cin>>t;

    while (t--)
        solve();

    system("pause");
    return 0;
}