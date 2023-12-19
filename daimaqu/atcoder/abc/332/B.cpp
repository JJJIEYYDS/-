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

void solve()
{
    cin >> n >> m >> k;
    ll t1 = 0, t2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (t2 == m)
        {
            t2 = 0;
            continue;
        }
        if (t1 != 0)
        {
            ll t = min(t1, m - t2);
            t2 += t;
            t1 -= t;
        }
        else
        {
            t1 = k;
        }
    }
    cout << t2 << ' ' << t1 << endl;
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