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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll sum[N];

void solve()
{
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    map<ll, ll> mp;

    for (int i = 1; i <= n; i++)
    {
        ll x = sum[i], y = sum[n] - sum[i];

        mp[a[i]] = i * a[i] - x + i + y - (n - i) * a[i] + (n - i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << mp[b[i]] << ' ';
    }
    cout << endl;
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