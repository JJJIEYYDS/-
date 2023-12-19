#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <array>

using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef unsigned long long ULL;
typedef long long ll;
const int N = 2e6 + 10, M = 31 * N;

ll n, m, k, q;
int ma[M][2], cnt[M], idx; // 存的是异或前缀和
ll f[40], a[N];

void add(ll x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!ma[p][u])
        {
            ma[p][u] = ++idx;
        }
        p = ma[p][u];
        cnt[p]++;
    }
}

void query(ll x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!ma[p][u])
        {
            return;
        }
        p = ma[p][u];
        f[i] += cnt[p];
    }
}
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] ^= a[i - 1]; // 每次添加一个数，能够产生，1~i，2~i`` i~i
        //  通过01字典树来快速处理
        for (int j = 30; j >= 0; j--)
        {
            if (a[i] >> j & 1)
            {
                break;
            }
            f[j] += 1;
        }
        query(a[i]);
        add(a[i]);
    }
    while (q--)
    {
        ll x;
        cin >> x;
        cout << f[x] << endl;
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