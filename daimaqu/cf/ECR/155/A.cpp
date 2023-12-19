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
PLL a[N];
int s, x;

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    s = a[1].first, x = a[1].second;
    bool flag = false;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].first >= s && a[i].second >= x)
            flag = true;
    }

    if (flag)
    {
        cout << -1 << endl;
        return;
    }

    cout << s << endl;
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