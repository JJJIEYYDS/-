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
ll a[N];
void init()
{
    a[1] = 1;
    for (int i = 2; i <= 15; i++)
    {
        a[i] = a[i - 1] * i;
    }
}

void solve()
{
    cin >> n;
    init();
    ll ans = 1e18;
    ll r = 1, l = 1;
    if (n == 2 || n == 1)
    {
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    for (int i = 3; i <= 12; i++)
    {
        ll y = n / (a[i] - 1);
        for (ll j = max(y - 10, (ll)1); j <= y + 10; j++)
        {
            if (j == 2)
                continue;
            if (ans > abs(j * a[i] - j - n))
            {
                ans = abs(j * a[i] - j - n);
                l = i, r = j;
            }
        }
    }
    cout << l << ' ' << r << endl;
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