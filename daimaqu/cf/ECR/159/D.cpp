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
map<PLL, vector<int>> mp;
set<PLL> st;

bool check(PLL a, int l, int r)
{
    if (!mp.count(a))
        return false;
    auto t = lower_bound(mp[a].begin(), mp[a].end(), l);
    return t != mp[a].end() && *t <= r;
}

void solve()
{
    mp.clear();
    cin >> n >> q;
    cin >> s;
    vector<PLL> p(n + 1);
    for (int i = 0; i < n; i++)
    {
        p[i + 1].first = p[i].first + (s[i] == 'R') - (s[i] == 'L');
        p[i + 1].second = p[i].second + (s[i] == 'U') - (s[i] == 'D');
    }

    for (int i = 0; i <= n; i++)
    {
        mp[p[i]].push_back(i);
    }

    for (int i = 1; i <= q; i++)
    {
        int l, r, x, y;
        cin >> x >> y >> l >> r;
        ll nx = p[r].first + p[l - 1].first - x, ny = p[r].second + p[l - 1].second - y;
        if (check({x, y}, 0, l - 1) || check({nx, ny}, l, r - 1) || check({x, y}, r, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
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