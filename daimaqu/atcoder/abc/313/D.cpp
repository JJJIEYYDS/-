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

    vector<int> a(n + 1), b(n + 1);
    int res = 0;
    for (int i = 1; i <= k + 1; i++)
    {
        cout << "?";
        for (int j = 1; j <= k + 1; j++)
        {
            if (i != j)
                cout << " " << j;
        }
        cout << endl;
        cin >> a[i];
        res += a[i];
    }

    for (int i = 1; i <= k + 1; ++i)
    {
        a[i] = (res - a[i]);
        a[i] %= 2;
    }
    int y = 0;
    for (int i = 1; i <= k - 1; i++)
        y += a[i];
    y %= 2;
    for (int i = k + 2; i <= n; i++)
    {
        cout << "?";
        for (int j = 1; j < k; j++)
        {
            cout << " " << j;
        }
        cout << ' ' << i << endl;
        cin >> a[i];
        a[i] = a[i] - y + 2;
        a[i] %= 2;
    }

    cout << "!";
    for (int i = 1; i <= n; i++)
    {
        cout << ' ' << a[i];
    }
    cout << endl;
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

    // system("pause");
    return 0;
}