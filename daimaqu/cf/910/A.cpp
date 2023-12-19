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
    cin >> n >> m;
    cin >> s;
    vector<ll> a(n + 10, 0);
    s = ' ' + s;
    ll cnt = 0;
    for (int i = s.size() - 1; i >= 1; i--)
    {
        if (s[i] == 'B')
        {
            cnt++;
        }
        if (i != s.size() - 1)
        {
            a[i] = a[i + 1] + (s[i + 1] == 'B');
        }
    }
    if (cnt == m)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= s.size() - 1; i++)
    {
        if (i == m && a[i] == 0)
        {
            cout << 1 << endl;
            cout << i << ' ' << 'B' << endl;
            return;
        }
        if (a[i] == m)
        {
            cout << 1 << endl;
            cout << i << ' ' << 'A' << endl;
            return;
        }
        if (i + a[i] == m)
        {
            cout << 1 << endl;
            cout << i << ' ' << 'B' << endl;
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