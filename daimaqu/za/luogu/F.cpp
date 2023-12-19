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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll x[N];
ll p;

ll qsm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res % p;
}

ll sx(ll n)
{
    if (n < p)
    {
        return x[n];
    }
    return sx(n / p) * qsm(x[p - 1], n / p) % p * x[n % p] % p;
}

void solve()
{
    cin >> n;

    cout << sx(n) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t >> p;
    x[0] = 1;
    x[1] = 1;
    for (int i = 2; i <= p; i++)
    {
        x[i] = x[i - 1] * i % p;
    }

    while (t--)
        solve();

    system("pause");
    return 0;
}