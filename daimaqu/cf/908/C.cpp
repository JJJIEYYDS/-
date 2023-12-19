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

void solve()
{
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll t1 = 0, t2 = n - 1;
    bool flag1 = false, flag2 = false;
    if (a[n - 1] > n)
    {
        cout << "No" << endl;
        return;
    }
    if (a[n - 1] == n)
    {
        cout << "Yes" << endl;
        return;
    }
    ll sum = 0;
    while (t1 <= min(n, k))
    {
        sum += a[t2];
        t2 = (n - 1 - sum + n) % n;
        if (sum > n)
        {
            sum -= n;
        }
        t1++;
        if (a[t2] == n)
        {
            flag1 = true;
            break;
        }
        if (a[t2] > n)
        {
            flag2 = true;
            break;
        }
    }

    if (flag1)
    {
        cout << "Yes" << endl;
        return;
    }
    if (flag2)
    {
        if (t1 < k)
        {
            cout << "No" << endl;
        }
        else
            cout << "Yes" << endl;
    }
    else
    {
        cout << "Yes" << endl;
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