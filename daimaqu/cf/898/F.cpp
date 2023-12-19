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
    cin >> n >> k;

    vector<ll> a(n + 1), b(n + 1);
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] <= k)
            flag = true;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    ll ans = 0;
    for (int i = 1, j = 1; i <= n; i++)
    {
        ll res = a[i];
        j = i;
        queue<ll> p;
        p.push(a[i]);
        while (j < n && b[j] % b[j + 1] == 0)
        {
            res += a[j + 1];
            p.push(a[j + 1]);
            while (res > k)
            {
                ll t = p.front();
                p.pop();
                res -= t;
            }
            ans = max((ll)p.size(), ans);
            j++;
        }
        i = j;
    }
    ans = max(ans, (ll)(flag == true));
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