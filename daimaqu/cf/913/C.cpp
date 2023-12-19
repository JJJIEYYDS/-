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
    map<PLL, ll> mp;
    vector<ll> a(26);
    for (int i = 0; i < s.size(); i++)
    {
        a[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != 0)
            mp[{a[i], i}] += 1;
    }
    while (mp.size() > 1)
    {
        auto t1 = *mp.begin(), t2 = *(--mp.end());
        mp.erase(mp.begin()), mp.erase((--mp.end()));
        if (t1.first.second == t2.first.second)
        {
            break;
        }
        if (t2.first.first - 1 != 0)
            mp[{t2.first.first - 1, t2.first.second}] += 1;
        if (t1.first.first - 1 != 0)
            mp[{t1.first.first - 1, t1.first.second}] += 1;
    }
    cout << (*mp.begin()).first.first << endl;
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