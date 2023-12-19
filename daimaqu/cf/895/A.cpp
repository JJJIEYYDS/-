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
    cin >> n >> m >> k;

    if (n < m)
        swap(n, m);
    ll cnt = 0;
    while (1)
    {
        if (abs(n - m) > k)
        {
            cnt++;
        }
        else
            break;
        n -= k;
        m += k;
    }
    if (n > m)
        cout << cnt + 1 << endl;
    else if (n < m)
        cout << cnt << endl;
    else
        cout << cnt << endl;
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