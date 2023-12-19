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

    vector<int> a(n + 1);
    ll res = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        res += a[i];
        if (a[i] == 1)
            cnt1++;
    }
    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    if (res >= (n - 1 + n))
    {
        cout << "YES" << endl;
        return;
    }
    ll k = res % n;
    if (k >= cnt1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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