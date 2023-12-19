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

void solve()
{
    cin >> n >> m >> k;
    if (k == 1)
    {
        cout << 1 << endl;
    }
    else if (k == 2)
    {
        if (m >= n)
            cout << m / n + n - 1 << endl;
        else
            cout << m << endl;
    }
    else if (k == 3)
    {
        if (m > n)
            cout << m - n - m / n + 1 << endl;
        else
        {
            cout << 0 << endl;
        }
    }
    else
    {
        cout << 0 << endl;
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