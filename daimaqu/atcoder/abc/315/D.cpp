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
const int N = 2500, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
char s[N][N];
bool st[N][N];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
        }
    }

    map<char, int> mp;
    for (int i = 1; i <= n; i++)
    {
        bool flag = false;
        for (int j = 1; j <= m; j++)
        {
            mp[s[i][j]]++;
        }
        for (auto [x, y] : mp)
        {
            if (y == 1)
                flag = 1;
        }
        if (!flag)
        {
            for (int j = 1; j <= m; j++)
            {
                st[i][j] = true;
            }
        }
        mp.clear();
    }
    mp.clear();
    for (int i = 1; i <= m; i++)
    {
        bool flag = false;
        for (int j = 1; j <= n; j++)
        {
            mp[s[j][i]]++;
        }
        for (auto [x, y] : mp)
        {
            if (y == 1)
                flag = 1;
        }
        if (!flag)
        {
            for (int j = 1; j <= n; j++)
            {
                st[j][i] = true;
            }
        }
        mp.clear();
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!st[i][j])
                ans++;
        }
    }

    cout << ans << endl;
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