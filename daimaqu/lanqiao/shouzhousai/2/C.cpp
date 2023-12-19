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
    vector<ll> a(n + 1), b(n + 1);
    // 长度为n划分k段，相当于删掉k-1两个数的极差
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 2; i <= n; i++)
    {
        b[i] = a[i] - a[i - 1];
    }
    sort(b.begin() + 2, b.end());
    ll sum = 0;

    for (int i = 2; i <= n - k + 1; i++)
    {
        sum += b[i];
    }
    cout << sum << endl;
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