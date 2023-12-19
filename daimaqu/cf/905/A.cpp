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
    cin >> s;
    ll ans = 0, t = 1;
    for (int i = 0; i < 4; i++)
    {
        if (s[i] == '0')
        {
            ans += abs(10 - t) + 1;
            t = 10;
            continue;
        }
        ans += abs(s[i] - '0' - t) + 1;
        t = s[i] - '0';
    }
    cout << ans << endl;
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