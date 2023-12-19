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
PLL a[N];
bool cmp(PLL a, PLL b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

bool check(ll x)
{
    vector<int> h, b;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].first >= x)
        {
            h.push_back(a[i].first + a[i].second - x);
        }
        else
            b.push_back(a[i].second);
    }
    sort(h.begin(), h.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    if (h.size() < b.size())
        return false;
    for (int i = 0; i < b.size(); i++)
    {
        if (h[i] < b[i])
            return false;
    }

    return true;
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a + 1, a + n + 1, cmp);

    ll l = 1, r = 1e9;
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    for (int i = 1; i <= n; i++)
        a[i].first = 0, a[i].second = 0;
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