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
bool cmp(PLL a, PLL b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}
ll n, m, k, q;

void solve()
{
    cin >> n >> m;
    vector<PLL> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].second;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
    }
    sort(a.begin() + 1, a.end(), cmp);
    ll t1 = 0, ans = 0;
    t1 = 1, ans += m;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].first < m)
        {
            if (t1 + a[i].second > n)
            {
                ans += (n - t1) * a[i].first;
                t1 = n;
                break;
            }
            else
            {
                t1 += a[i].second;
                ans += a[i].first * a[i].second;
            }
        }
    }
    if (t1 >= n)
    {
        cout << ans << endl;
    }
    else
    {
        cout << ans + (n - t1) * m << endl;
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