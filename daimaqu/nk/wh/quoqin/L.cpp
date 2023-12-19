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

ll a[100];
void init()
{
    a[0] = 1;
    for (int i = 1; i <= 31; i++)
    {
        a[i] = a[i - 1] * 2;
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i <= 31; i++)
    {
        if (a[i] > n)
        {
            cout << a[i] << endl;
            return;
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
    init();
    while (t--)
        solve();

    system("pause");
    return 0;
}