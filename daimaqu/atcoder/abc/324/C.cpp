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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
string t;
string s[N];
void solve()
{
    cin >> n;
    cin >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    map<ll, ll> mp;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == t)
        {
            mp[i]++;
            continue;
        }
        if (abs((ll)t.size() - (ll)s[i].size()) >= 2)
        {
            continue;
        }
        for (int j = 0; j < min((ll)t.size(), (ll)s[i].size()); j++)
        {
            if (s[i][j] != t[j])
            {
                string t1 = s[i].substr(j), t2 = s[i].substr(j + 1), t3 = t.substr(j), t4 = t.substr(j + 1);
                if (t2 == t3)
                {
                    mp[i]++;
                }
                if (t4 == t1)
                {

                    mp[i]++;
                }
                if (t2 == t4)
                {

                    mp[i]++;
                }
                if (t1 == t3)
                {

                    mp[i]++;
                }
                break;
            }
            if (s[i].size() < t.size() && j == s[i].size() - 1)
                mp[i]++;
            if (s[i].size() > t.size() && j == t.size() - 1)
            {
                mp[i]++;
            }
        }
    }
    cout << mp.size() << endl;
    for (auto [x, y] : mp)
    {
        cout << x << ' ';
    }
    cout << endl;
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