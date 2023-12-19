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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
vector<int> v[N];
bool st[N];

void dfs(int u)
{
    if (v[u].size() == 0)
    {
        if (st[u])
            return;
        st[u] = true;
        cout << u << ' ';
    }
    for (auto x : v[u])
    {
        if(!st[x]) dfs(x);
    }
    if (u != 1)
    {
        if (st[u])
            return;
        st[u] = true;
        cout << u << ' ';
    }
}
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
    dfs(1);
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