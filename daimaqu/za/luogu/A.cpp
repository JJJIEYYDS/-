#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <deque>

using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;

void solve()
{
    ll y;
    cin >> y >> n >> m;
    deque<ll> q;

    vector<ll> b(m + 1);
    for (int j = 1; j <= m; j++)
    {
        cin >> b[j];
    }
    vector<ll> dp(y + 1, INF);
    dp[0] = 0;
    q.push_back(0);
    for (int i = 1; i <= y; i++)
    {
        if (i > n)
        {
            while (q.size() && i - (ll)q.front() > n)
                q.pop_front();
        }
        ll t = dp[q.front()] + 1;
        dp[i] = min(dp[i], t);

        for (int j = 1; j <= m; j++)
        {
            if (i % b[j] == 0)
            {
                dp[i] = min(dp[i], dp[i / b[j]] + 1);
            }
        }
        while (q.size() && dp[q.back()] > dp[i])
            q.pop_back();
        q.push_back(i);
    }
    cout << dp[y] << endl;
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