#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;

void solve()
{
    cin >> n;
    vector<double> a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int j = 0; j < n; j++)
    {
        cin >> b[j];
        b[j] = (b[j]) / 100000.0;
    }
    double ans = n;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 0)
            continue;
        double res = i + (1 / b[i] - 1) * (i - a[i] + 1) + 1;
        ans = min(res, ans);
    }

    cout << fixed << setprecision(12) << ans << endl;
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