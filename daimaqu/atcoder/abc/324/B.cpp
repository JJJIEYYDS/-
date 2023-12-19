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
ll a[30], b[30];
set<ll> st;
void init()
{
    a[0] = b[0] = 1;
    st.insert(1);
    for (int i = 1; i <= 31; i++)
    {
        a[i] = a[i - 1] * 2;
        st.insert(a[i]);
    }
}
void solve()
{
    cin >> n;
    ll t = 1;
    for (int i = 1; i <= 31; i++)
    {
        if (n % t == 0)
        {
            if (st.find(n / t) != st.end())
            {
                cout << "Yes" << endl;
                return;
            }
        }
        t *= 3;
    }
    cout << "No" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    init();
    while (t--)
        solve();

    system("pause");
    return 0;
}