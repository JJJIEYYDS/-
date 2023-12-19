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
ll son[N][26], cnt[N], idx;
void insert(string s)
{
    ll p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ll u = s[i] - 'a';
        if (!son[p][u])
        {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    cnt[p]++;
}
ll query(string s)
{
    ll p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ll u = s[i] - 'a';
        if (!son[p][u])
        {
            return 0;
        }
        p = son[p][u];
    }
    return cnt[p];
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char op;
        string s;
        cin >> op >> s;
        if (op == '1')
        {
            insert(s);
        }
        else
        {
            cout << query(s) << endl;
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