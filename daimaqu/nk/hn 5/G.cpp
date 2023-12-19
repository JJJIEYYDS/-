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
map<ll, ll> mp;
void init()
{
    int cnt = 0;
    ll k = 2;
    for (int i = 3; i <= 1e9; i += k)
    {
        cnt++;
        mp[i] += cnt;
        k *= 2;
    }
}

void solve()
{
    cin >> n;
    int t = 0;
    for (auto [x, y] : mp)
    {
        if (x > n)
        {
            cout << t << endl;
            return;
        }
        t = x;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
        solve();

    system("pause");
    return 0;
}