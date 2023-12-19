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
    vector<PLL> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[i] = {x, x + y};
    }
    sort(a.begin() + 1, a.end());

    ll now = 1;
    ll ptr = 1;
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    while (ptr <= n || q.size())
    {
        if (!q.size())
        {
            now = a[ptr].first;
        }
        while (ptr <= n && a[ptr].first == now)
            q.push(a[ptr++].second);
        while (q.size() && q.top() < now)
            q.pop();
        if (q.size())
        {
            ans++;
            q.pop();
        }
        now++;
    }
    cout << ans << endl;
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