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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    if (n == 1)
    {
        cout << fixed << setprecision(1) << (double)a[1] << endl;
        return;
    }
    ll x = a[1], y = a[n];
    if (y - a[2] + x >= a[2])
    {
        cout << fixed << setprecision(1) << (double)a[2]<< endl;
    }
    else
    {
        double x1 = (double)(y + x) / 2;
        cout << fixed << setprecision(1) << x1 << endl;
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