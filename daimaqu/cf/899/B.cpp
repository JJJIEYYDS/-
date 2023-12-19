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

void solve()
{
    cin >> n;
    map<ll, vector<ll>> mp1, mp2;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            cin >> y;
            mp1[y].push_back(i);
        }
    }
    mp2 = mp1;
    int t = mp1.size();
    for (auto [x, y] : mp1)
    {
        mp2 = mp1;
        for ()
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