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
    cin >> n >> m;
    cin >> s >> t;

    k = s.size();
    string t1 = t.substr(0, n), t2 = t.substr(max((ll)t.size() - k, (ll)0), n);

    if (t1 == s && t2 == s)
    {
        cout << 0 << endl;
    }
    else if (t1 == s)
    {
        cout << 1 << endl;
    }
    else if (t2 == s)
    {
        cout << 2 << endl;
    }
    else
        cout << 3 << endl;
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