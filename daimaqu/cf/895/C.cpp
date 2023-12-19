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
const int N = 1e7 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
bool st[N];
ll p[N], cnt = 0;
void init()
{
    for (int i = 2; i <= 1e7; i++)
    {
        if (!st[i])
            p[cnt++] = i;
        for (int j = 0; i * p[j] <= 1e7; j++)
        {
            st[i * p[j]] = true;
            if (i % p[j] == 0)
                break;
        }
    }
}
void solve()
{
    int l, r;
    cin >> l >> r;
    if (r <= 3)
    {
        cout << -1 << endl;
        return;
    }
    if (r % 2 == 0)
    {
        cout << r / 2 << ' ' << r / 2 << endl;
    }
    else
    {
        if (l == r)
        {
            if (!st[r])
                cout << -1 << endl;
            else
            {
                for (int i = 0; i <= cnt; i++)
                {
                    if (r % p[i] == 0)
                    {
                        ll k = r / p[i];
                        cout << (k) / 2 * p[i] << ' ' << (k - (k) / 2) * p[i] << endl;
                        return;
                    }
                }
            }
        }
        else
        {
            cout << (r - 1) / 2 << ' ' << (r - 1) / 2 << endl;
        }
    }
    cout << cnt << endl;
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