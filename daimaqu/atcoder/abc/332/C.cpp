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
    cin >> n >> m;
    cin >> s;
    ll t1 = m, t2 = 0, t3 = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (t1 >= 1)
            {
                t1--;
            }
            else
            {
                if (t2 >= 1)
                {
                    t2--;
                }
                else
                {
                    ans++;
                    t3++;
                }
            }
        }
        else if (s[i] == '2')
        {
            if (t2 >= 1)
            {
                t2--;
            }
            else
            {
                ans++;
                t3++;
            }
        }
        else
        {
            t2 = t3;
            t1 = m;
        }
    }
    cout << ans << endl;
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