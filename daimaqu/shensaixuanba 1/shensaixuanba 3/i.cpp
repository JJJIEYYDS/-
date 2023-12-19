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

bool st[N];

void solve()
{
    std::cin >> n >> q;

    vector<int> e(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[a] ^= c, e[b] ^= c;
    }

    while (q--)
    {
        int op, a, b, c;
        cin >> op;
        if (op == 1)
        {

            cin >> a >> b >> c;
            e[a] ^= c, e[b] ^= c;
        }
        else if (op == 2)
        {
            cin >> a;

            cout << e[a] << endl;
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