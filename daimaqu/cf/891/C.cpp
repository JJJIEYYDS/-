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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
int b[N];

void solve()
{
    cin >> n;
    if (n == 2)
    {
        int b;
        cin >> b;
        cout << b << ' ' << b << endl;
        return;
    }
    map<int, int> mp;
    for (int i = 1; i <= n * (n - 1) / 2; i++)
    {
        cin >> b[i];
        mp[b[i]]++;
    }

    if (mp.size() == n)
    {
        for (auto [x, y] : mp)
        {
            cout << x << ' ';
        }
    }
    else
    {
        int t = 1;
        for (auto [x, y] : mp)
        {
            while (t <= n && y >= n - t)
            {
                cout << x << ' ';
                y -= (n - t);
                t++;
            }
        }
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