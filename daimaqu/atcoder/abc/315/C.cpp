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
bool cmp(PLL a, PLL b)
{
    return a.second > b.second;
}

void solve()
{
    cin >> n;
    vector<PLL> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end(), cmp);
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].first == a[1].first)
            ans = max(ans, a[1].second + a[i].second / 2);
        else
            ans = max(ans, a[1].second + a[i].second);
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