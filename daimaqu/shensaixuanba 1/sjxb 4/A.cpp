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
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}
void solve()
{
    cin >> n >> k;
    vector<PLL> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin() + 1, a.end(), cmp);

    ll sum = 0;
    ll t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].first != t)
            sum += (a[i].first - t) * k;
        t = a[i].first;
        if (a[i].second <= sum)
            sum -= a[i].second;
        else
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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