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
ll a[N];
bool st[N];
ll mx;

void dfs(int u)
{
    if (u > n)
    {
        ll ans = 0, mx1 = 0;
        for (int i = 1; i <= n; i++)
        {
            mx1 = max(mx1, i * a[i]);
            ans += i * a[i];
        }
        ans -= mx1;
        if (ans >= mx)
        {
            mx = max(mx, ans);
            cout << mx << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << a[i] << ' ';
            }
            cout << endl;
        }

        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            a[u] = i;
            dfs(u + 1);
            st[i] = false;
        }
    }
}
void solve()
{
    cin >> n;
    dfs(1);
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