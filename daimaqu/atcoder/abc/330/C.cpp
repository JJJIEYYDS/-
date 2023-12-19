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
set<ll> st;

void init()
{
    for (ll i = 0; i <= 2e6; i++)
    {
        st.insert(i * i);
    }
}
void solve()
{
    cin >> m;
    if (st.count(m))
    {
        cout << 0 << endl;
        return;
    }
    ll ans = 1e9;
    for (ll i = 0; i <= 2e6; i++)
    {
        if (i * i >= m)
        {
            ans = min(ans, abs(i * i - m));
        }
        else
        {
            if (st.count(m - i * i))
            {
                ans = min(ans, 0ll);
            }
            else
            {
                ans = min(ans, abs(((ll)sqrt(m - i * i) + 1) * ((ll)sqrt(m - i * i) + 1) + i * i - m));
                ans = min(ans, abs(((ll)sqrt(m - i * i) - 1) * ((ll)sqrt(m - i * i) - 1) + i * i - m));
                ans = min(ans, abs(((ll)sqrt(m - i * i)) * ((ll)sqrt(m - i * i)) + i * i - m));
            }
        }
    }

    cout << ans << endl;
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