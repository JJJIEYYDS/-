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
    ll a, b, c;
    cin >> a >> b >> c;
    ll zk, zj, a1, b1;
    cin >> zk >> a1 >> zj >> b1;
    ll ans = (zj - zk - 1) * 4;
    for (int i = a1; i <= 7; i++)
    {
        if (i != a && i != b && i != c)
        {
            ans++;
        }
    }
    for (int i = 1; i <= b1 - 1; i++)
    {
        if (i != a && i != b && i != c)
        {
            ans++;
        }
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