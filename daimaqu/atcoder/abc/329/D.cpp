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
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
struct node
{
    ll x, y;
    bool operator<(const node &p) const
    {
        if (x == p.x)
        {
            return y > p.y;
        }
        return x < p.x;
    }
};
void solve()
{
    cin >> n >> m;
    priority_queue<node> p;
    map<ll, ll> mp;
    for (int i = 1; i <= m; i++)
    {
        ll x;
        cin >> x;
        mp[x]++;
        p.push({mp[x], x});
        ll t1 = p.top().y;
        cout << t1 << endl;
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