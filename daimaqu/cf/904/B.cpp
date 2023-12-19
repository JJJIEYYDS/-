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
string s;

void solve()
{
    cin >> n;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<ll> a(n + 100);
    for (int i = 0, j = 0; i < n; i++)
    {
        while (i + j < n && s[j + i] == '1')
            j++;
        if (i + j > n - 1)
        {
            a[i] = -1;
            continue;
        }
        a[i] = j;
    }
    cout << a[0] << ' ';
    for (int i = 1; i < n; i++)
    {
        if (a[i] == -1)
        {
            cout << -1 << ' ';
            continue;
        }
        a[i] += a[i - 1];
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