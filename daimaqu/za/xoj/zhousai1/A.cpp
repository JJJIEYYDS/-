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
string a, b, s;

ll toint(string s, ll x)
{
    ll res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'F')
        {
            res = res * x + (s[i] - 'A') + 10;
        }
        else
            res = res * x + s[i] - '0';
    }
    return res;
}
void solve()
{
    cin >> a >> b >> s;
    for (int i = 16; i >= 2; i--)
    {
        ll t1 = toint(a, i), t2 = toint(b, i), t3 = toint(s, i);
        if (t1 + t2 == t3)
        {
            cout << i << endl;
            return;
        }
    }
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