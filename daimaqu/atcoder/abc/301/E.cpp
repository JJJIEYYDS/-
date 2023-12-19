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

ll n, m, k, q, t;

char s[500][500];
int dis[20][500][500];
bool st[500][500];
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

vector<PII> c;

int dp[1 << 20][20];

void bfs(int x1, int y1, int num)
{
    queue<PII> p;
    p.push({x1, y1});
    dis[num][x1][y1] = 0;

    while (p.size())
    {
        auto t = p.front();
        p.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] != '#' && dis[num][x][y] > dis[num][t.first][t.second] + 1)
            {
                dis[num][x][y] = dis[num][t.first][t.second] + 1;
                p.push({x, y});
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> t;
    int s1 = 0, s2 = 0;
    int e1 = 0, e2 = 0;
    for (int i = 0; i < 20; i++)
    {
        memset(dis[i], INF, sizeof dis[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == 'S')
            {
                s1 = i, s2 = j;
            }
            if (s[i][j] == 'G')
            {
                e1 = i, e2 = j;
            }
            if (s[i][j] == 'o')
            {
                c.push_back({i, j});
            }
        }
    }

    int cnt = c.size();
    for (int i = 0; i < cnt; i++)
    {
        bfs(c[i].first, c[i].second, i);
    }
    memset(dp, INF, sizeof dp);

    for (int i = 0; i < cnt; i++)
    {
        dp[1 << i][i] = dis[i][s1][s2];
    }

    for (int i = 1; i < (1 << cnt); i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            if (dp[i][j] == INF)
                continue;
            for (int k = 0; k < cnt; k++)
            {
                if ((i >> k) & 1)
                    continue;
                int x = c[k].first, y = c[k].second;
                if (dp[i | (1 << k)][k] > dp[i][j] + dis[j][x][y])
                {
                    dp[i | (1 << k)][k] = dp[i][j] + dis[j][x][y];
                }
            }
        }
    }

    bfs(s1, s2, 19);
    if (dis[19][e1][e2] > t)
    {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    for (int i = 1; i < (1 << cnt); i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            if (dp[i][j] + dis[j][e1][e2] <= t)
            {
                int num = 0;
                for (int k = 0; k < cnt; k++)
                {
                    if ((i >> k) & 1)
                        num++;
                }
                ans = max(ans, num);
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