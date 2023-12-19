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

ll n, m, k, q, p;
struct node
{
    int val;
    ll a[150];
    bool operator>(node const &p) const
    {
        return val > p.val;
    }
} v[150];
void solve()
{
    cin >> n >> k >> p;
    vector<ll> b(k + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].val;
        for (int j = 1; j <= k; j++)
        {
            cin >> v[i].a[j];
            b[j] += v[i].a[j];
        }
    }
    for (int i = 1; i <= k; i++)
    {
        if (b[k] < p)
        {
            cout << -1 << endl;
            return;
        }
    }
    sort(v + 1, v + n + 1, greater<node>());
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