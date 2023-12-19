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
const int N = 1010, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
char s[N][N];
bool st[N][N];
int dx[] = {0, -1, 0, 1, -1, 1, 1, -1}, dy[] = {1, 0, -1, 0, -1, 1, -1, 1};
void bfs(int x, int y)
{
    queue<PLL> q;
    q.push({x, y});
    st[x][y] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int xx = t.first + dx[i], yy = t.second + dy[i];

            if (!st[xx][yy] && s[xx][yy] == '#')
            {
                st[xx][yy] = true;
                q.push({xx, yy});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> s[i][j];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (s[i][j] == '#' && !st[i][j])
            {
                ans++;
                bfs(i, j);
            }
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