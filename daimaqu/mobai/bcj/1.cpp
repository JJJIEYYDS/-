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
ll p[N];
ll find(ll x)
{
    if (x != p[x])
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> c >> a >> b;
        ll pa = find(a), pb = find(b);

        if (c == 1)
        {
            if (pa != pb)
            {
                p[pa] = pb;
            }
        }
        else
        {
            if (pa == pb)
            {
                cout << "Yes" << endl;
            }
            else
                cout << "No" << endl;
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