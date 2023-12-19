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
const int N = 5e5 + 10, INF = 0x3f3f3f3f;

int n, m, k;
int a[N], b[N];

bool check(ll x)
{
    ll cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= x)
            cnt1++;
    }
    for (int i = 1; i <= m; i++)
    {
        if (b[i] >= x)
            cnt2++;
    }

    return cnt1 >= cnt2;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= m; j++)
    {
        cin >> b[j];
    }

    ll l = 1, r = 1e18;

    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;
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