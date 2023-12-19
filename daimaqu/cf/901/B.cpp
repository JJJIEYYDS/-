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
    cin >> n >> m >> k;
    vector<ll> a(n + 1), b(m + 1);
    ll minn = 1e18, maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        minn = min(a[i], minn);
        maxx = max(maxx, a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        min
    }
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    bool flag = false;
    if (a[1] < b[m])
        swap(a[1], b[m]);
    else if (a[1] > b[m])
    {
        flag = true;
        k += 1;
    }
    else
    {
        if (k % 2 == 0)
            k += 1;
    }

    if (k % 2 == 0 && !flag)
    {
        swap(a[n], minn);
    }
    ll t = 0;
    for (int i = 1; i <= n; i++)
    {
        t += a[i];
    }
    cout << t << endl;
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