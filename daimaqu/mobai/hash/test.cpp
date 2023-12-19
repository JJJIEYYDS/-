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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
const int mod1 = 805306457, mod2 = 1610612741;
map<pair<ll, ll>, ll> mp[N];
ll p = 131;

void solve()
{
    cin >> n;

    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        char op;
        string s;
        cin >> op >> s;
        if (op == '1')
        {
            ll cnt1 = 0, cnt2 = 0;
            s = ' ' + s;

            for (int j = 1; j <= s.size(); j++)
            {
                if (s.substr(j, 6) == "lenovo")
                {
                    cnt2++;
                }
            }
            ll sum1 = 0, sum2 = 0;

            for (int j = 1; j <= s.size(); j++)
            {
                sum1 = sum1 * p % mod1 + s[j];
                sum2 = sum2 * p % mod2 + s[j];
                if (s.substr(j, 6) == "lenovo")
                {
                    // cout << j << endl;
                    cnt1++;
                }
                if (cnt1)
                {
                    mp[j][{sum1, sum2}] += (cnt1 == cnt2);
                    // cout << j << endl;
                }
            }
            cnt += (cnt2 > 0);
        }
        else
        {
            ll sum1 = 0, sum2 = 0;
            for (int i = 0; i < s.size(); i++)
            {
                sum1 = sum1 * p % mod1 + s[i];
                sum2 = sum2 * p % mod2 + s[i];
            }
            cout << cnt - mp[s.size()][{sum1, sum2}] << endl;
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