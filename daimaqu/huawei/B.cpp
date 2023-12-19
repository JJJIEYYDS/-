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
string s1, s2;
void solve()
{
    cin >> n;
    cin >> s1 >> s2;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '1')
            cnt1++;
    }
    for (int i = 0; i < n; i++)
    {
        if (s2[i] == '1')
            cnt2++;
    }

    ll x = cnt2 + cnt1;
    if (x > n)
    {
        x = (n - (x - n));
        for (int i = 0; i < x; i++)
        {
            cout << 1;
        }
        for (int i = x; i < n; i++)
            cout << 0;
        cout << endl;
    }
    else
    {
        for (int i = 0; i < x; i++)
            cout << 1;
        for (int i = x; i < n; i++)
        {
            cout << 0;
        }
        cout << endl;
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