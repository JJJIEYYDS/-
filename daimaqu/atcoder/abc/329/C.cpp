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
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;

string s;

void solve()
{
    cin >> n;
    cin >> s;
    char s1 = s[0];
    ll cnt = 1;
    map<char, ll> mp;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s1)
        {
            mp[s1] = max(mp[s1], cnt);
            s1 = s[i];
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    mp[s1] = max(cnt, mp[s1]);
    ll ans = 0;
    for (auto [x, y] : mp)
    {
        ans += y;
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