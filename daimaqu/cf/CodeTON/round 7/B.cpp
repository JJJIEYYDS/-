#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <array>

using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef unsigned long long ULL;
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;

string s;

void solve()
{
    cin >> n;

    cin >> s;
    s = ' ' + s;
    ll cnta = 0, cntb = 0;
    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'A')
        {
            if (cnta == 0)
            {
                cntb = 0;
            }
            cnta++;
        }
        else
        {
            cntb++;
            if (cnta >= 1 && cntb >= 1 && (i + 1 == n + 1 || s[i + 1] == 'A'))
            {
                ans += cntb;
                ans += cnta - 1;
                cnta = 1;
                cntb = 0;
            }
        }
    }
    if (cnta >= 1 && cntb >= 1 && s[n] != 'A')
    {
        ans += cntb;
        ans += cnta - 1;
        cnta = 1;
        cntb = 0;
    }
    cout << min(ans, n - 1) << endl;
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