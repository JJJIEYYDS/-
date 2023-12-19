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
    cin >> s;
    ll t1 = s[1] - '0';
    char t2 = s[0];
    for (int i = 1; i <= 8; i++)
    {
        if (i != t1)
        {
            cout << s[0] << i << endl;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if ('a' + i != t2)
        {
            cout << (char)('a' + i) << t1 << endl;
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