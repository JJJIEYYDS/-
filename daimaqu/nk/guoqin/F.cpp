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
const int N = 5010, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int a[N][N], b[N][N];
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = i * j / __gcd(i, j);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int t = 1;
        deque<int> q;

        for (int j = 1; j <= k; j++)
        {
            while (q.size() && a[i][q.back()] <= a[i][j])
                q.pop_back();
            q.push_back(j);
        }
        b[i][t] = a[i][q.front()];
        for (int j = k + 1; j <= m; j++)
        {
            while (q.size() && a[i][q.back()] < a[i][j])
                q.pop_back();
            q.push_back(j);
            while (q.size() && j - k + 1 > q.front())
                q.pop_front();
            t++, b[i][t] = a[i][q.front()];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        deque<int> q;
        for (int j = 1; j <= k; j++)
        {
            while (q.size() && b[q.back()][i] <= b[j][i])
                q.pop_back();
            q.push_back(j);
        }
        ans += b[q.front()][i];
        for (int j = k + 1; j <= n; j++)
        {
            while (q.size() && b[j][q.back()] <= b[j][i])
                q.pop_back();
            q.push_back(j);
            while (q.size() && j - k + 1 > q.front())
                q.pop_front();
            ans += b[q.front()][i];
        }
    }
    cout << ans << endl;
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