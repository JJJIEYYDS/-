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
vector<ll> a, b;
void solve()
{
    cin >> n >> m;
    a = vector<ll>(n + 1), b = vector<ll>(n + 1);

    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    sort(b.begin() + 1, b.end());
    ll ans = 0;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        while (j <= n && a[i] >= b[j])
            j++;
        if (j <= n && b[j] > a[i])
        {
            ans++;
            j++;
        }
    }
    cout << n - ans << endl;
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