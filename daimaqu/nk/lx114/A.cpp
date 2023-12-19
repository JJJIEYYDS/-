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
int a[10];
bool st[10];
char s[10];
ll mx;
ll toint()
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

void dfs(int u)
{
    if (u > n)
    {
        ll t = toint();
        if (t > mx)
        {
            mx = t;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            s[u] = a[i] + '0';
            dfs(u + 1);
            st[i] = false;
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1);
    if (mx == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << 0;
        }
        cout << endl;
        return;
    }
    if (mx % 10 == 0)
        cout << mx << endl;
    else
        cout << -1 << endl;
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