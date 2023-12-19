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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
string s;
bool st[N];

PLL dfs(int x)
{
    if (x > n - 1)
    {
        return {0, n - 1};
    }
    vector<ll> v;
    v.push_back(x - 1);
    for (int i = 0; i < 2; i++)
    {
        if (x > n - 1)
        {
            return {0, n - 1};
        }
        // cout << x << endl;
        if (s[x] == 'A')
        {
            auto t1 = dfs(x + 1);
            if (t1.first == 0)
            {
                return t1;
            }
            x = t1.second;
            while (s[x] == 'A')
            {
                auto t1 = dfs(x + 1);
                if (t1.first == 0)
                {
                    return t1;
                }

                x = t1.second;
            }
        }
        // cout << s[v[i]] << ' ' << (char)(s[x] - 1) << ' ' << x << endl;
        if (s[v[i]] == (char)(s[x] - 1))
        {
            v.push_back(x);
        }
        else
        {
            return {0, x - 1};
        }

        x += 1;
    }
    for (auto y : v)
    {
        st[y] = true;
    }
    return {1, x};
}
void solve()
{
    cin >> s;

    n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != 'A')
        {
        }
        else
        {
            auto t1 = dfs(i + 1);
            if (t1.first == 0)
            {
                i = t1.second;
            }
            else
            {
                i = t1.second - 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!st[i])
        {
            cout << s[i];
        }
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