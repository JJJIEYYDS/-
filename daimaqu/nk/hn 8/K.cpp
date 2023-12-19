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
bool st[N];
map<ll, ll> mp;
ll p[N], cnt;
ll sum[N];
void init()
{
    for (int i = 2; i <= 1e6 + 10; i++)
    {
        if (!st[i])
        {
            p[cnt++] = i;
            sum[i] = cnt;
        }
        for (int j = 0; i * p[j] <= 1e6 + 10; j++)
        {
            st[i * p[j]] = true;
            if (i % p[j] == 0)
                break;
        }
    }
    p[cnt] = 1e6 + 10;
    for (int i = 0; i <= cnt; i++)
    {
        for (int j = p[i] + 1; j <= p[i + 1] - 1; j++)
        {
            sum[j] = sum[p[i]];
        }
    }
}
void solve()
{
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l - 1] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
        solve();

    system("pause");
    return 0;
}