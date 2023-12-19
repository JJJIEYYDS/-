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
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (a[1] == 1)
    {
        b[1] = 2;
    }
    else
    {
        b[1] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        if (b[i - 1] + 1 == a[i])
        {
            b[i] = b[i - 1] + 2;
        }
        else
        {
            b[i] = b[i - 1] + 1;
        }
    }
    cout << b[n] << endl;
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