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
    vector<ll> a(n + 1), b;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    b.push_back(a[1]);
    for (int i = 2; i <= n; i++)
    {
        if (a[i] >= a[i - 1])
            b.push_back(a[i]);
        else
        {
            b.push_back(1);
            b.push_back(a[i]);
        }
    }
    cout << b.size() << endl;
    for (auto x : b)
    {
        cout << x << ' ';
    }
    cout << endl;
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