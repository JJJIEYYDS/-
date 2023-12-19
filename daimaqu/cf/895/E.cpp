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
string s;
void solve()
{
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> s;
    s = ' ' + s;
    vector<ll> b(n + 1);
    ll a1 = 0, a0 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            a1 ^= a[i];
        }
        else
            a0 ^= a[i];
        b[i] = b[i - 1] ^ a[i];
    }

    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        ll op, x, y;
        cin >> op;
        if (op == 2)
        {
            cin >> x;
            if (x == 1)
            {
                cout << a1 << endl;
            }
            else
                cout << a0 << endl;
        }
        else
        {
            cin >> x >> y;
            ll res = b[x - 1] ^ b[y];
            a0 ^= res;
            a1 ^= res;
        }
    }
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