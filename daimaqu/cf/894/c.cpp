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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k = 2e5, q;
ll b[N];

void solve()
{
    cin >> n;

    vector<ll> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (a[1] != n)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        b[1]++;
        b[a[i] + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        c[i] = b[i] + c[i - 1];
    }
    b[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        b[a[i] + 1] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != c[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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