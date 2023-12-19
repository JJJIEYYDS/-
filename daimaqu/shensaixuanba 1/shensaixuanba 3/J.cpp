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
    vector<vector<ll>> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int b;
        cin >> b;
        v[i].push_back(b);
    }
    cin >> q;
    while (q--)
    {
        ll op, a, b;
        cin >> op;
        if (op == 0)
        {
            cin >> a >> b;
            v[a].push_back(b);
        }
        else
        {
            cin >> a;
            ll ans = INF;
            for (int i = max((ll)1, a - (ll)sqrt(n)); i <= min(n, (ll)sqrt(n) + a); i++)
            {
                for (auto x : v[i])
                    ans = min((i - a) * (i - a) + x, ans);
            }

            cout << ans << endl;
        }
    }
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