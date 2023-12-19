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
    vector<int> a(n + 1);
    vector<int> b[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= a[i]; j++)
        {
            int x;
            cin >> x;
            b[i].push_back(x);
        }
    }
    queue<ll> p;
    p.push(1);
    set<PLL> st;
    vector<PLL> c;
    while (p.size())
    {
        auto t = p.front();
        p.pop();
        c.push_back({a[t], t});
        cout << t << ' ' << a[t] << endl;
        for (auto x : b[t])
        {
            p.push(x);
        }
    }
    sort(c.begin(), c.end());

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