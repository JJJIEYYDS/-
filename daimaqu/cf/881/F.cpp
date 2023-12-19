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
int mx[N], mi[N], ansmx[N], ansmi[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        mx[i] = mi[i] = ansmi[i] = ansmx[i] = 1;
    }

    int cnt = 1;
    mx[1] = mi[1] = ansmx[1] = ansmi[1] = 1;

    for (int i = 1; i <= n; i++)
    {
        char op;
        int a, b, w;
        cin >> op;
        if (op == '+')
        {
            cin >> a >> b;
            cnt++;
            mx[cnt] = max(mx[a] + b, b);
            mi[cnt] = min(mi[a] + b, b);
            ansmi[cnt] = min(mi[cnt], ansmi[a]);
            ansmx[cnt] = max(mx[cnt], ansmx[a]);
        }
        else
        {
            cin >> a >> b >> w;
            if (w == 0 || ansmi[b] <= w && ansmx[b] >= w)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
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