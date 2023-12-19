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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;

void solve()
{
    cin >> n;
    multiset<ll> st;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    ll t = 0, ans = 0;
    while (st.size())
    {
        ll pre = *st.begin(), sux = *(--st.end());
        if (st.size() == 1)
        {
            ll t1 = sux - t;
            pre -= (t1 + 1) / 2;
            ans += (t1 + 1) / 2;
            if (pre > 0)
                ans += 1;
            st.erase(st.begin());
            continue;
        }
        if (t >= sux)
        {
            t = 0;
            ans += 1;
            st.erase((--st.end()));
            continue;
        }
        if (pre + t < sux)
        {
            t += pre;
            ans += pre;
            pre = 0;
        }
        else
        {
            ll temp = sux - t;
            pre -= temp;
            ans += temp;
            t += temp;
        }
        st.erase(st.begin());
        if (pre)
            st.insert(pre);
    }
    cout << ans << endl;
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