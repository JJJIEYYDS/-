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

ll n, m, k, q, x;

void solve()
{
    cin >> k;
    vector<int> a(k + 1);
    ll res = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }

    cin >> n >> m >> x;
    x %= m;
    for (int i = 1; i <= k; i++)
    {
        a[i] %= m;
        res += a[i];
    }

    ll b = x + (res) * (n / k);
    for (int i = 1; i <= n % k; i++)
    {
        b += a[i];
    }
    cout << n - b / m << endl;
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