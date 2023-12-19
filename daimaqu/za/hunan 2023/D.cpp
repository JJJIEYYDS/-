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
    map<ll, priority_queue<ll, vector<ll>, greater<ll>>> mp;
    for (int i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        mp[a].push(b);
    }
    cin >> m;
    ll ans = 0;
    bool flag = false;
    for (int i = 1; i <= m; i++)
    {
        }
    if (!flag)
        cout << ans << endl;
    else
        cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    system("pause");
    return 0;
}