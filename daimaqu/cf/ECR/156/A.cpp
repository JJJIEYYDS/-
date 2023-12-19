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
    cin >> n;
    if (n < 7 || n == 9)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (n % 3 == 0)
    {
        cout << 1 << ' ' << 4 << ' ' << n - 5 << endl;
    }
    else
    {
        cout << 1 << ' ' << 2 << ' ' << n - 3 << endl;
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