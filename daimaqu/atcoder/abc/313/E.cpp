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
string s;

void solve()
{
    cin >> n >> s;
    s = ' ' + s;

    for (int i = 1; i < n; i++)
    {
        if (s[i] != '1' && s[i + 1] != '1')
        {
            cout << -1 << endl;
            return;
        }
    }
    ll ans = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        ans = (ans + 1 + (s[i + 1] - '1') * ans) % mod;
    }

    cout << ans % mod -1<< endl;
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
// 13130
// 1113111
// 11111311
// 111111131
// 1111111113
// 11111111111