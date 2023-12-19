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
    ll pos;
    cin >> pos;
    n = s.size();
    ll x = 0, y = 0;
    for (ll i = 0; i < n; i++)
    {
        ll len = n - i;
        if (pos <= len)
        {
            x = i;
            y = pos;
            break;
        }
        pos -= len;
    }

    string t;
    for (auto c : s)
    {
        while (x > 0 && t.size() && t.back() > c)
        {
            t.pop_back();
            x--;
        }
        t += c;
    }
    cout << t[y - 1];
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
    cout << endl;
    system("pause");
    return 0;
}