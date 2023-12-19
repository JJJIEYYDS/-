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
const int N = 1010, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
int g[N][N], v[N][N];

void solve()
{
    cin >> n >> m;
    vector<vector<int>> h1(n + 1), h2(n + 1), w1(m + 1), w2(m + 1), a, b, c, d;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            h1[i].push_back(g[i][j]);
            w1[j].push_back(g[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
            h2[i].push_back(v[i][j]);
            w2[j].push_back(v[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(h1[i].begin(), h1[i].end());
        sort(h2[i].begin(), h2[i].end());
        for (int j = 0; j < m; j++)
        {
            if (h1[i][j] != h2[i][j])
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        sort(w1[i].begin(), w1[i].end());
        sort(w2[i].begin(), w2[i].end());
        for (int j = 0; j < n; j++)
        {
            if (w1[i][j] != w2[i][j])
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    ll res = 0;
    ll ans = 1e9;
    for (int i = 1; i <= m; i++)
    {
        if (g[1][i] != v[1][i])
        {
            for (int j = i + 1; j <= m; j++)
            {
            }
        }
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