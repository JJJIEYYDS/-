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
string s;
bool st[100];
ll a[100];
ll ans;
map<ll, ll> mp, mp1;

void solve()
{
    cin >> n;
    cin >> s;
    vector<ll> a(15);
    for (int i = 0; i < n; i++)
    {
        a[s[i] - '0']++;
    }
    // dfs(1); 13阶乘超时
    for (ll i = 0; i <= 6e6; i++)
    {
        ll j = i * i;
        vector<ll> b(10);
        while (j)
        {
            b[j % 10]++;
            j /= 10;
        }
        bool flag = false;
        for (int k = 0; k <= 9; k++)
        {
            if (b[k] < a[k] && k == 0)
            {
                continue;
            }
            if (b[k] != a[k])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            ans++;
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