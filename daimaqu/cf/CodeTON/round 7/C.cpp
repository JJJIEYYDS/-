#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <array>

using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef unsigned long long ULL;
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;

void solve()
{
    cin >> n >> k;
    vector<PLL> a(n + 1);
    vector<ll> b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin() + 1, a.end(), greater<PLL>());
    sort(b.begin() + 1, b.end(), greater<ll>());
    ll ans = 0;
    ll t1 = n - k + 1, t2 = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i <= k)
        {
            c[a[i].second] = b[t1];
            if (a[i].first > b[t1++])
            {
                ans++;
            }
        }
        else
        {
            c[a[i].second] = b[t2];
            if (a[i].first > b[t2++])
            {
                ans++;
            }
        }
    }
    if (ans == k)
    {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << c[i] << ' ';
        }
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
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