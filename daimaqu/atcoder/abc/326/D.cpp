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
string t1, t2;
char s[10][10];
ll c[10][5];
bool flag;

void dfs(int u)
{
    if (flag)
        return;
    if (u == n)
    {
        string str;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[j][i] != '.')
                {
                    str += s[j][i];
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (s[j][i] != '.')
                    cnt++;
            }
            if (cnt != 3)
                return;
        }

        if (str == t2 && !flag)
        {
            flag = true;
            cout << "Yes" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << s[i][j];
                }
                cout << endl;
            }
        }
        return;
    }

    for (int i = 0; i < (1 << n); i++)
    {
        if (flag)
            return;
        vector<ll> p;
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
                p.push_back(j);
        }
        if (p.size() != 3)
            continue;
        if (!c[p[0]][t1[u] - 'A'])
        {
            s[u][p[0]] = t1[u];
            c[p[0]][t1[u] - 'A'] = 1;
            char t3 = 'A', t4 = 'B';
            if (t1[u] == 'A')
                t3 = 'C';
            if (t1[u] == 'B')
                t4 = 'C';
            if (!c[p[1]][t3 - 'A'] && !c[p[2]][t4 - 'A'])
            {
                c[p[1]][t3 - 'A'] = c[p[2]][t4 - 'A'] = 1;
                s[u][p[1]] = t3, s[u][p[2]] = t4;
                dfs(u + 1);
                if (flag)
                    return;
                s[u][p[1]] = '.', s[u][p[2]] = '.';
                c[p[1]][t3 - 'A'] = c[p[2]][t4 - 'A'] = 0;
            }

            if (!c[p[1]][t4 - 'A'] && !c[p[2]][t3 - 'A'])
            {
                c[p[1]][t4 - 'A'] = c[p[2]][t3 - 'A'] = 1;
                s[u][p[1]] = t4, s[u][p[2]] = t3;
                dfs(u + 1);
                if (flag)
                    return;
                s[u][p[1]] = '.', s[u][p[2]] = '.';
                c[p[1]][t4 - 'A'] = c[p[2]][t3 - 'A'] = 0;
            }
            s[u][p[0]] = '.';
            c[p[0]][t1[u] - 'A'] = 0;
        }
    }
}
void solve()
{
    cin >> n;
    cin >> t1 >> t2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s[i][j] = '.';
        }
    }

    dfs(0);

    if (!flag)
        cout << "No" << endl;
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