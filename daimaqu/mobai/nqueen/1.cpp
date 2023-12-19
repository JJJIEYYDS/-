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
const int N = 1000, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
char s[N][N];
ll a[N], b[N], c[N], d[N];

void dfs(int u)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << s[i][j];
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!a[u] && !b[i] && !c[i + u] && !d[i - u + n])
        {
            a[u] = true, b[i] = true, c[i + u] = true, d[i - u + n] = true;
            s[u][i] = 'Q';
            dfs(u + 1);
            s[u][i] = '.';
            a[u] = false, b[i] = false, c[i + u] = false, d[i - u + n] = false;
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            s[i][j] = '.';
        }
    }
    dfs(1);
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