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
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    ll ans = 0;
    for (int i = 0; i < 24; i++)
    {
        ll res = 0;
        for (int j = 1; j <= n; j++)
        {
            ll t1 = (i + b[j]) % 24, t2 = (i + 1 + b[j]) % 24;
            if (t1 > t2)
                swap(t1, t2);
            if (t1 >= 9 && t2 <= 18)
            {
                res += a[j];
            }
        }
        ans = max(res, ans);
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