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
string s[N], t;
ll pre[N], sux[N];
ll sx[N];

ll deal1(int x)
{
    ll k = 0;
    for (int i = 0; i < s[x].size(); i++)
    {
        if (s[x][i] == t[k])
        {
            k++;
        }
    }
    return k;
}
ll deal2(int x)
{
    ll k = t.size() - 1, t1 = 0;
    for (int i = s[x].size() - 1; i >= 0; i--)
    {
        if (s[x][i] == t[k])
        {
            t1++;
            k--;
        }
    }
    return t1;
}
void solve()
{
    cin >> n;
    cin >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++)
    {
        pre[i] = deal1(i);
        // cout << i << ' ' << pre[i] << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        sux[i] = deal2(i);
        // cout << i << ' ' << sux[i] << endl;
        sx[sux[i]]++;
    }

    for (int i = N - 5; i >= 0; i--)
    {
        sx[i] += sx[i + 1];
    }
    ll ans = 0;
    ll t1 = t.size();
    for (int i = 1; i <= n; i++)
    {
        ll t = max(t1 - pre[i], 0ll);
        ans += sx[t];
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