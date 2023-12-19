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
    cin >> n >> k;
    vector<ll> a(n + 1);
    vector<ll> b(25);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[(a[i] % k)]++;
    }
    ll ans = 1e5;
    if (k == 2 || k == 3 || k == 5)
    {
        if (b[0] >= 1)
        {
            ans = 0;
        }
        else
        {
            for (int i = k - 1; i >= 1; i--)
            {
                if (b[i])
                {
                    ans = min(ans, k - i);
                    break;
                }
            }
        }
    }
    else
    {
        if (b[0] >= 1)
        {
            ans = 0;
        }
        else
        {
            for (int i = k - 1; i >= 1; i--)
            {
                if (b[i])
                {
                    ans = min(ans, k - i);
                    break;
                }
            }

            vector<ll> v;
            for (int i = 1; i <= k - 1; i++)
            {
                for (int j = 1; j <= b[i]; j++)
                {
                    if (abs(2 - i) != 0)
                        v.push_back(abs(2 - i));
                }
            }
            sort(v.begin(), v.end());
            if (b[2] >= 2)
            {
                ans = min(ans, 0ll);
            }
            else if (b[2] == 1)
            {
                ans = min(v[0], ans);
            }
            else
            {

                if (v.size() >= 2)
                    ans = min(ans, v[0] + v[1]);
                else
                {
                    ans = min(ans, abs(v[0] - 4));
                }
            }
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
    cin >> t;

    while (t--)
        solve();

    system("pause");
    return 0;
}