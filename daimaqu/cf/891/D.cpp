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
    vector<ll> a(n + 1), b(n + 1);
    vector<PLL> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        v[i] = {(a[i] - b[i]), i};
    }

    sort(v.begin() + 1, v.end(), greater<PLL>());
    vector<ll> ans;
    ll t1 = v[1].first;
    ans.push_back(v[1].second);
    for (int i = 2; i <= n; i++)
    {
        if (v[i].first == t1)
            ans.push_back(v[i].second);
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << ' ';
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