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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

ll n, m, k, q;
ll b[N], a[N];
ll qsm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res % mod;
}
void solve()
{
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        b[l1]++, b[r1 + 1]--;
        b[l2]++, b[r2 + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i] + a[i - 1];
    }

    for (int i = 1; i <= 5e5; i++)
    {
        if (a[i] == n)
        {
            ans = (ans + 1) % mod;
        }
        else if (a[i] > n)
        {
            a[i] -= n;
            ans = (ans + qsm(2, a[i])) % mod;
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