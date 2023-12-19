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
string s;

void solve()
{
    cin >> n;
    cin >> s;
    ll cnt = 0, res = 0;
    ll sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            res = max(res, cnt);
            cnt = 0;
        }
        else
        {
            cnt++;
            sum++;
        }
    }
    res = max(res, cnt);
    if (res >= 3)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << sum << endl;
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