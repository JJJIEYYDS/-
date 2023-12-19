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

void solve()
{
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> b(n + 10);
    // 总够n个数，它的mex取值只可能0~n，只需存储0~n，把0~n这之间的数存进set之中，值后枚举这些可能取值

    set<ll> st;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= n)
        {
            b[a[i]]++;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        if (b[i] == 0)
            st.insert(i);
    }

    for (int i = 1; i <= q; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;

        if (a[x] <= n)
        {
            if (b[a[x]] == 1)
                st.insert(a[x]);

            b[a[x]]--;
        }

        a[x] = y;
        st.erase(y);
        if (a[x] <= n)
        {
            b[a[x]]++;
        }

        cout << *st.begin() << endl;
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