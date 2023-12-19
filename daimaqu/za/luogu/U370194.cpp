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
string s, t;

void solve()
{
    cin >> s >> t;
    ll t1 = s[0] - 'A', t2 = t[0] - 'A';
    ll sum = t1 + t2;
    if (sum < 26)
    {
        cout << (char)(sum + 'A') << endl;
        return;
    }
    while (sum >= 26)
    {
        ll t;

        t = sum / 26 % 26,
        sum -= t * 26;
        cout << (char)(t + 'A');
    }
    cout << (char)(sum + 'A') << endl;
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