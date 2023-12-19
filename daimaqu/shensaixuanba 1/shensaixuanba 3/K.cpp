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
    vector<int> sum(n), b(n);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
    {
        b[i] = a[i] - a[i + 1];
    }
    sort(b.begin() + 1, b.end());
    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + b[i];
    }
    cin >> q;
    while (q--)
    {
        int op, a;
        cin >> op;
        if (op == 0)
        {
            cin >> a;
        }
        else
        {
            cin >> a;
            ll ans = 0;
            cout << sum[n - a] << endl;
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