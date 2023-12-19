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
    cin >> s1 >> s2;

    array<int, 5> a{3600, 60, 1};
    ll ans1 = 0;
    ll t = 0, k = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] >= '0' && s1[i] <= '9')
        {
            t = t * 10 + (s1[i] - '0');
        }
        else
        {
            ans1 += (t)*a[k++];
        }
    }
    ll ans2 = 0;
    t = 0, k = 0;
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] >= '0' && s2[i] <= '9')
        {
            t = t * 10 + (s2[i] - '0');
        }
        else
        {
            ans1 += (t)*a[k++];
        }
    }
    cout << ans2 - ans1 << endl;
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