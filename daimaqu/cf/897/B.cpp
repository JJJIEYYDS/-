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

#define int long long

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;

void solve()
{
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    int cnt = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (s[i] != s[n - i + 1])
            cnt++;
    }
    for (int i = 0; i <= n; i++)
    {
        if (i == n)
        {
            if (cnt == 0)
                cout << 1;
            else
                cout << 0;
            continue;
        }
        if (i == cnt)
            cout << 1;
        else if (i > cnt)
        {
            if (n % 2 == 0)
            {
                if (i <= cnt + n - cnt * 2 && (i - cnt) % 2 == 0)
                {
                    cout << 1;
                }
                else
                    cout << 0;
            }
            else
            {
                if (i <= cnt + n - 2 * cnt)
                    cout << 1;
                else
                    cout << 0;
            }
        }
        else
            cout << 0;
    }
    cout << endl;
}

signed main()
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