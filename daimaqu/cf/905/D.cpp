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
    map<ll, ll> mp1, mp2;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        char c;
        ll x, y;
        cin >> c >> x >> y;

        if (c == '+')
        {
            mp1[x]++, mp2[y]++;
        }
        else if (c == '-')
        {
            if (mp1[x] > 1)
                mp1[x]--;
            else
                mp1.erase(x);

            if (mp2[y] > 1)
                mp2[y]--;
            else
                mp2.erase(y);
        }

        if (mp1.size() < 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            ll l = (--mp1.end())->first, r = mp2.begin()->first;
            if (l > r)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
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