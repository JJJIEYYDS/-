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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;

vector<PLL> a;
string s;
ll ans;
char s1[3];

void dfs(int u, ll w)
{
    if (a[u].first == 0 && a[u].second == 0)
    {
        // cout << u << endl;
        ans = min(ans, w);
        return;
    }
    if (s[u] == 'L')
    {
        if (a[u].first != 0)
            dfs(a[u].first, w);
        if (a[u].second != 0)
            dfs(a[u].second, w + 1);
    }
    if (s[u] == 'U')
    {
        if (a[u].first != 0)
            dfs(a[u].first, w + 1);
        if (a[u].second != 0)
            dfs(a[u].second, w + 1);
    }
    if (s[u] == 'R')
    {
        if (a[u].first != 0)
            dfs(a[u].first, w + 1);
        if (a[u].second != 0)
            dfs(a[u].second, w);
    }
}
void solve()
{
    s1[0] = 'L', s1[1] = 'R', s1[2] = 'U';
    cin >> n;
    ans = 1e9;
    a = vector<PLL>(n + 1);
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    dfs(1, 0);
    cout << ans << endl;
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