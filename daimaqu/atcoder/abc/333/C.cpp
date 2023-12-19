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

void solve()
{
    cin >> n;

    vector<ll> v;
    ll t1 = 1;
    for (int i = 1; i <= 18; i++)
    {
        v.push_back(t1);
        t1 *= 10;
        t1 += 1;
    }
    ll res1 = 0, res2 = 0;
    ll ans = 0;
    for (int i = 0; i < 18; i++)
    {
        res2 += i + 1;
        ans = res1;
        res1 += res2;

        if (res1 >= n)
        {
            for (int j = 0; j <= i; j++)
            {
                for (int k = 0; k <= j; k++)
                {
                    ans++;
                    if (ans == n)
                    {
                        cout << v[i] + v[j] + v[k] << endl;
                        return;
                    }
                }
            }
        }
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