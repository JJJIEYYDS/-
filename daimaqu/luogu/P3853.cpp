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
ll a[N];

bool check(ll x)
{
    // cout << x << endl;
    ll cnt = 0;
    for (int i = 2; i <= m; i++)
    {
        if (a[i] - a[i - 1] > x)
        {
            ll t = x;
            while (a[i - 1] + t < a[i])
            {
                t += x;
            }
            t -= x;
            cnt += t / x;
        }
    }
    return cnt <= k;
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    ll l = 0, r = 1e9;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        // cout << mid << ' ' << l << ' ' << r << endl;
        //  cout << mid << endl;
        if (check(mid))
        {
            r = mid;
        }
        else
            l = mid + 1;
    }
    cout << l << endl;
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