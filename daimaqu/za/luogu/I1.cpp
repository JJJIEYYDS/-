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

long long n, k, m;
struct Matrix
{
    long long a[3][3];

    Matrix() { memset(a, 0, sizeof a); }

    Matrix operator*(const Matrix &b) const
    {
        Matrix res;
        for (register int i = 1; i <= 2; ++i)
            for (register int j = 1; j <= 2; ++j)
                for (register int k = 1; k <= 2; ++k)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % m;
        return res;
    }
} ans, base;

inline void init()
{
    base.a[1][1] = k;
    base.a[1][2] = 1;
    base.a[2][1] = -1;
    ans.a[1][1] = (k * k - 2) % m;
    ans.a[1][2] = k % m;
}

inline void qpow(long long b)
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
    if (n == 0)
    {
        cout << 2 << endl;
        return;
    }
    if (n == 1)
    {
        printf("%lld", k);
        return;
    }
    if (n == 2)
    {
        printf("%lld", (k * k - 2) % m);
        return;
    }
    init();
    qpow(n - 2);
    printf("%lld", (ans.a[1][1] + m) % m);
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