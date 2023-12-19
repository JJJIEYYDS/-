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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
string s;
ll a[N];

void init()
{
    a[0] = 1;

    for (int i = 1; i <= 2e5 + 10; i++)
    {
        a[i] = (a[i - 1] * i) % mod;
    }
}

void solve()
{
    cin >> s;
    ll cnt = 1, len = 0;
    ll cnt0 = 0, cnt1 = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            cnt0++;
            if (cnt1 != 0 && cnt1 != 1)
            {
                cnt = cnt1 * cnt % mod;
                len += (cnt1 - 1);
            }
            cnt1 = 0;
        }
        else
        {
            cnt1++;
            if (cnt0 != 0 && cnt0 != 1)
            {
                cnt = cnt * (cnt0) % mod;
                len += (cnt0 - 1);
            }
            cnt0 = 0;
        }
    }
    if (cnt0 != 0 && cnt0 != 1)
    {
        cnt = cnt * cnt0 % mod;
        len += (cnt0 - 1);
        cnt0 = 0;
    }
    if (cnt1 != 0 && cnt1 != 1)
    {
        cnt = cnt1 * cnt % mod;
        len += (cnt1 - 1);
        cnt1 = 0;
    }

    cnt = (cnt * a[len]) % mod;
    cout << len << ' ' << cnt << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
        solve();

    system("pause");
    return 0;
}