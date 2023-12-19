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
string s[N];

ll son[N][26], cnt[N], idx;

void insert(string str)
{
    ll p = 0;
    for (int i = 0; i < str.size(); i++)
    {
        ll u = str[i] - 'a';
        if (!son[p][u])
        {
            son[p][u] = ++idx;
        }
        p = son[p][u];
        cnt[p]++;
    }
}

ll query(string str)
{
    ll res = 0;
    ll p = 0;
    for (int i = 0; i < str.size(); i++)
    {
        ll u = str[i] - 'a';
        if (!son[p][u])
        {
            return res;
        }
        p = son[p][u];
        res += cnt[p] * 2;
    }
    return res;
}
void solve()
{
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        sum += s[i].size() * (n + 1) + s[i].size() * (n - 1);
        insert(s[i]);
    }
    ll ans = sum;
    for (int i = 1; i <= n; i++)
    {
        reverse(s[i].begin(), s[i].end());
        // cout << query(s[i]) << endl;
        ans -= query(s[i]);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    system("pause");
    return 0;
}