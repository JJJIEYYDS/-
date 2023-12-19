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
    string s;
    cin >> n >> m;
    cin >> s;
    vector<ll> a(k + 1), b(k + 1);

    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
    }
    cin >> q;
    map<ll, ll> mp;
    map<PLL, ll> mp1;
    for (int i = 1, j = 1; i <= n; i++)
    {
        while (j <= k && (a[j] > i || b[j] < i))
        {
            j++;
        }
        mp[i] = b[j] + a[j] - i;
    }

    vector<ll> v(q + 1);
    for (int i = 1; i <= q; i++)
    {
        ll x;
        cin >> x;
        ll t1 = min(x, mp[x]), t2 = max(x, mp[x]);
        if (t1 == t2)
            continue;
        mp1[{t1, t2}]++;
    }
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