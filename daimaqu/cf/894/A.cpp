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
const int N = 250, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
char s[N][N];

void solve()
{
    cin >> n >> m;
    map<int, set<char>> mp2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
            mp2[j].insert(s[i][j]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (mp2[i].find('v') != mp2[i].end())
        {
            for (int j = i + 1; j <= m; j++)
            {
                if (mp2[j].find('i') != mp2[j].end())
                {
                    for (int k = j + 1; k <= m; k++)
                    {
                        if (mp2[k].find('k') != mp2[k].end())
                        {
                            for (int v = k + 1; v <= m; v++)
                            {
                                if (mp2[v].find('a') != mp2[v].end())
                                {
                                    cout << "YES" << endl;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
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