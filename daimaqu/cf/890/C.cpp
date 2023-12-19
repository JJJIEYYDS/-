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
bool check(ll x, vector<ll> a)
{
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        ll t = k, ans = x;
        for (int j = i; j <= n; j++)
        {
            if (a[j] < ans)
            {
                if (j == n)
                    t = -1;
                t -= (ans - a[j]);
                ans--;
            }
            else
                break;
        }
        if (t >= 0)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        return true;
    }
    else
        return false;
}

void solve()
{
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll l = 0, r = 1e9;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid, a))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;
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