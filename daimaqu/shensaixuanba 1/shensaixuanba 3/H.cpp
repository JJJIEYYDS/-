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
const int N = 1e7 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll w[N], v[N], dp[N];

void solve()
{
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 0;
    }

    for (int i = 1, j = 1; i <= n; i++)
    {
        j = i + 1;
        while (j <= n && a[j] < a[i])
        {
            j++;
        }
        b[i] = j - i;
        i = j - 1;
    }
    map<ll, ll> mp;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] != 0)
            mp[b[i]]++;
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) != mp.end())
        {
            int k = 1;
            while (k <= mp[i])
            {
                cnt++;
                v[cnt] = (i * k);
                w[cnt] = (i * k);
                mp[i] -= k;
                k *= 2;
            }
            if (mp[i] > 0)
            {
                cnt++;
                v[cnt] = mp[i] * i;
                w[cnt] = mp[i] * i;
            }
        }
    }

    for (int i = 1; i <= cnt; i++)
    {
        for (int j = n / 2; j >= v[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    if (dp[n / 2] == n / 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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