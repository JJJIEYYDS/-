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
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin() + 1, a.end());
    if (mp[a[n]] == n)
    {
        cout << -1 << endl;
        return;
    }
    cout << n - mp[a[n]] << ' ' << mp[a[n]] << endl;
    for (int i = 1; i <= n - mp[a[n]]; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    for (int i = n - mp[a[n]] + 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
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