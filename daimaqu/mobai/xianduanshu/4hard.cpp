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

const int N = 2e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
// #define endl '\n'

ll n, m, k, q;
struct node
{
    ll l, r;
    ll sum;
} tr[N << 2];

ll a[N];

struct ask
{
    ll pos;
    ll sum;
};

set<ll> st;

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r)
{

    tr[u].l = l, tr[u].r = r;
    tr[u].sum = 0;
    // cout << u << ' ' << tr[u].l << ' ' << tr[u].r << endl;
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
        // cout << u << ' ' << tr[u].l << ' ' << tr[u].r << endl;
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

ask query(int u, int l, int r, ll sum, ll x)
{
    if (l == r)
    {
        ask temp;
        temp.sum = sum + tr[u].sum;
        temp.pos = l;
        return temp;
    }
    int mid = (l + r) >> 1;
    if (sum + tr[u << 1].sum >= x)
        return query(u << 1, l, mid, sum, x);
    else
        return query(u << 1 | 1, mid + 1, r, sum + tr[u << 1].sum, x);
}

void solve()
{
    cin >> n >> m;
    cout << n << "\n";

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            st.insert(i);
        }
    }

    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        char op;
        cin >> op;
        ll l, x;
        if (op == 'A')
        {
            cin >> x;
            ask t = query(1, 1, n, 0, x);
            ll pos = t.pos;
            ll sum = t.sum;
            // cout << 111111 << ' ' << pos << ' ' << sum << endl;
            if (x == 0 || tr[1].sum < x)
            {
                // cout << tr[1].sum << endl;
                cout << "none" << endl;
                continue;
            }

            if (sum == x)
            {
                cout << 1 << ' ' << pos << endl;
                continue;
            }
            ll pos1 = INF, pos2 = INF, len = pos - 1;

            if (st.size())
                pos1 = *st.begin();
            auto t1 = st.lower_bound(pos);
            if (t1 != st.end())
                pos2 = *t1;
            if (pos1 + len > n && pos2 > n)
            {
                cout << "none" << endl;
                continue;
            }
            if (pos1 - 1 >= pos2 - pos)
            {
                cout << pos2 - len << ' ' << pos2 << endl;
            }
            else
            {
                cout << pos1 + 1 << ' ' << pos1 + len << endl;
            }
        }
        else
        {
            cin >> l >> x;

            if (a[l] == 1)
                st.erase(l);
            a[l] = x;
            if (a[l] == 1)
                st.insert(l);
            modify(1, l, x);
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