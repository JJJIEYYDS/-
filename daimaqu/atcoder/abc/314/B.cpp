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

vector<vector<int>> v(N + 1);
vector<vector<int>> e(N + 1);

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            int y;
            cin >> y;
            v[i].push_back(y);
        }
    }

    cin >> m;

    int res = 1e4, cnt1 = 0;
    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        for (auto x : v[i])
        {
            if (x == m)
            {
                if (v[i].size() <= res)
                {
                    e[v[i].size()].push_back(i);
                    res = v[i].size();
                }
                break;
            }
        }
    }
    cout << e[res].size() << endl;
    for (auto x : e[res])
    {
        cout << x << ' ';
    }
    cout << endl;
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