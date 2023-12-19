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

void solve()
{
    map<char, ll> mp;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    if (mp.size() != 2)
    {
        cout << "No" << endl;
    }
    else
    {
        bool flag1 = 0, flag3 = 0;
        for (auto [x, y] : mp)
        {
            if (y == 1)
                flag1 = true;
            if (y == 3)
                flag3 = true;
        }
        if (flag1 && flag3)
        {
            cout << "Yes" << endl;
        }
    }
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