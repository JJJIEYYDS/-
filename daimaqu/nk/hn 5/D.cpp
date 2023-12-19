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
    ll ans = 1;
    ll res = 1;
    string s1 = s;

    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '?')
            s1[i] = '0';
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s1[i] == s1[i + 1])
        {
            res++;
        }
        else
        {
            ans = max(ans, res);
            res = 1;
        }
    }
    ans = max(res, ans);
    res = 1, s1 = s;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '?')
            s1[i] = '1';
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s1[i] == s1[i + 1])
        {
            res++;
        }
        else
        {
            ans = max(ans, res);
            res = 1;
        }
    }
    ans = max(res, ans);
    cout << ans << endl;
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