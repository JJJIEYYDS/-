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
    vector<ll> a(n + 1);
    map<ll, ll> mp1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp1[a[i]]++;
    }

    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        ll x1 = (x - sqrt(x * x - 4 * y)) / 2, x2 = (x + sqrt(x * x - 4 * y)) / 2;
        if (((ll)sqrt(x * x - 4 * y) * (ll)sqrt(x * x - 4 * y)) != (x * x - 4 * y))
        {
            cout << 0 << ' ';
            continue;
        }
        if ((x - (ll)sqrt(x * x - 4 * y)) % 2 == 0 && (x + (ll)sqrt(x * x - 4 * y)) % 2 == 0)
        {
            if (x1 == x2)
            {
                cout << mp1[x1] * (mp1[x1] - 1) / 2 << ' ';
            }
            else
                cout << mp1[x1] * mp1[x2] << ' ';
        }
        else
            cout << 0 << ' ';
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