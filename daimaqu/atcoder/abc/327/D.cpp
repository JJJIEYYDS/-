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

vector<ll> st;

vector<vector<ll>> v(N);
bool flag;

void dfs(int u, int fa)
{
    for (auto x : v[u])
    {
        if (x == fa)
            continue;
        if (st[x] != -1)
        {
            if (st[x] == st[u])
                flag = true;
        }

        else
        {
            st[x] = !st[u];
            if (flag)
            {
                return;
            }
            dfs(x, u);
        }
    }
}
void solve()
{
    cin >> n >> m;
    st = vector<ll>(n + 1, -1);
    vector<ll> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= m; i++)
    {
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (st[i] == -1)
        {
            st[i] = 0;
            dfs(i, 0);
        }
        if (flag)
        {
            break;
        }
    }
    if (flag)
    {
        cout << "No" << endl;
    }
    else
        cout << "Yes" << endl;
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