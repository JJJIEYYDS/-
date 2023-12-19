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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

ll n, m, k, q;

struct matrix
{
    ll a[3][3];
    matrix() { memset(a, 0, sizeof a); }
    matrix operator*(const matrix &b) const
    {
        matrix res;

        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= 2; j++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    res.a[i][j] = (res.a[i][j] + (a[i][k] * b.a[k][j])) % m;
                }
            }
        }
        return res;
    }
} ans, base;

void init()
{
    base.a[1][1] = (k), base.a[1][2] = 1, base.a[2][1] = -1, base.a[2][2] = 0;
    ans.a[1][1] = (k * k % m - 2 + m) % m, ans.a[1][2] = (k);
}

void qpow(ll b)
{
    while (b)
    {
        if (b & 1)
            ans = ans * base;
        base = base * base;
        b >>= 1;
    }
}

void solve()
{
    cin >> m >> k >> n;
    init();
    if (n == 0)
    {
        cout << 2 << endl;
        return;
    }
    if (n == 1)
    {
        cout << k % m << endl;
        return;
    }
    if (n == 2)
    {
        cout << (k * k % m - 2 + m) % m << endl;
        return;
    }
    init();
    qpow(n - 2);
    cout << (ans.a[1][1] + m) % m << endl;
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