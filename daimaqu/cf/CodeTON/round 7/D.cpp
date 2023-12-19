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

ll n, m, k, q;
ll a[N];

struct node
{
    int l, r;
    ll sum;
} tr[N * 4];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    tr[u].sum = 0;
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

void modify(int u, int l, int x)
{
    if (tr[u].l >= l && tr[u].r <= l)
    {
        tr[u].sum = x;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid)
    {
        modify(u << 1, l, x);
    }
    else
    {
        modify(u << 1 | 1, l, x);
    }
    pushup(u);
}

ll query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        return tr[u].sum;
    }

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
    cin >> n >> q;
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            st.insert(i);
        }
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        int op, x, y;
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            if (st.size() == 0)
            {
                if (x % 2 == 0)
                {
                    if (x / 2 <= n)
                    {
                        cout << "Yes" << endl;
                    }
                    else
                    {
                        cout << "No" << endl;
                    }
                }
                else
                {
                    cout << "No" << endl;
                }
                continue;
            }
            ll t1 = *st.begin(), t2 = *(--st.end());
            ll t5 = t1 - 1, t6 = n - t2;

            ll t3 = query(1, t1, n);
            ll t4 = query(1, 1, t2);

            if ((x <= t3 || x <= t4) || ((x - t3) % 2 == 0 && (x - t3) / 2 <= t5) || ((x - t4) % 2 == 0 && (x - t4) / 2 <= t6))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cin >> x >> y;
            modify(1, x, y);
            if (a[x] == 1)
                st.erase(x);
            a[x] = y;
            if (a[x] == 1)
                st.insert(x);
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