#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <bitset>
using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll a[N];
bool st[N];
ll mx;
string s[4];
string str;

void dfs(int u)
{
    if (u > 4)
    {
        ll ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            ans = ans * 2 + str[i] - '0';
        }
        if (ans > mx)
        {
            mx = ans;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            string t = str;
            str += s[i];
            dfs(u + 1);
            str = t;
            st[i] = false;
        }
    }
}

void solve()
{
    cin >> n;
    bitset<32> b(n);
    int cnt = 0;
    for (int i = 0; i < 32; i++)
    {
        if (i % 8 == 0 && i != 0)
            cnt++;
        s[cnt] += (b[i] + '0');
    }
    dfs(1);
    cout << mx << endl;
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