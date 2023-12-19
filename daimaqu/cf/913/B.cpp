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
    cin >> s;
    set<ll> a, b;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' && s[i] != 'b')
        {
            a.insert(i);
        }
        if (s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'B')
        {
            b.insert(i);
        }
        if (s[i] == 'b')
        {
            if (a.size())
            {
                a.erase((--a.end()));
            }
        }
        if (s[i] == 'B')
        {
            if (b.size())
            {
                b.erase((--b.end()));
            }
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if ((a.find(i) != a.end()) || (b.find(i) != b.end()))
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
    cin >> t;

    while (t--)
        solve();

    system("pause");
    return 0;
}