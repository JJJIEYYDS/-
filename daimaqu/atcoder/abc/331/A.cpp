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
ll x, y;

void solve()
{
    ll a, b, c;
    cin >> x >> y;
    cin >> a >> b >> c;
    if (c + 1 > y)
    {
        if (b + 1 > x)
        {
            cout << a + 1 << ' ' << 1 << ' ' << 1 << endl;
        }
        else
        {
            cout << a << ' ' << b + 1 << ' ' << 1 << endl;
        }
    }
    else
    {
        cout << a << ' ' << b << ' ' << c + 1 << endl;
    }
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