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
    cin >> n >> m;
    vector<int> a;
    if (m == 1)
    {
        cout << 0 << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << 0 << ' ';
            }
            cout << endl;
        }
        return;
    }
    if (n >= m - 1)
    {
        for (int i = 0; i < m; i++)
        {
            a.push_back(i);
        }
        cout << m << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[j] << ' ';
            }
            cout << endl;
            if (i < m - 1)
            {
                ll t = a.front();
                a.erase(a.begin());
                a.push_back(t);
            }
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            a.push_back(i);
        }
        cout << n + 1 << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[j] << ' ';
            }
            cout << endl;
            if (i < n)
            {
                ll t = a.front();
                a.erase(a.begin());
                a.push_back(t);
            }
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