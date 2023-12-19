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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
int s[4], f[N];

void solve()
{
    cin >> m >> n;

    if (m % 3 ^ n)
    {
        cout << "Alice" << endl;
    }
    else
        cout << "Bob" << endl;
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