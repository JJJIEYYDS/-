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
    cin >> n >> m;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> cnt(n + 1);
    for (int i = n; i >= 1; i--)
    {
        if (a[i] + 1 == a[i + 1])
            cnt[i] = cnt[i + 1] + 1;
        else
            cnt[i] = 1;
    }

    map<ll, vector<ll>> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[a[i]].push_back(i);
    }
    int ans = 0, pos = 1, flag = 0;
    while (1)
    {
        ll mx = -1;

        for (auto x : mp[pos])
            mx = max(mx, cnt[x]);
        if (mx == -1)
        {
            flag = true;
            break;
        }
        ans++;
        pos = mx + 1;
        if (pos > m)
            break;
    }
    if (flag)
        cout << -1 << endl;
    else
    {
        cout << ans << endl;
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