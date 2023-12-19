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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans1 = 0, res = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        ans2 += abs(a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)
        {
            int j = i;
            while (j <= n && a[j] <= 0)
            {

                j++;
            }
            ans1++;
            i = j - 1;
        }
    }

    cout << ans2 << ' ' << ans1 << endl;
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