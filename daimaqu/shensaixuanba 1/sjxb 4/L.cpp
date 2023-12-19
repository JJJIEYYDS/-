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
ll x1, y1;
int dx[] = {-1, 1, 1, -1}, dy[] = {-1, 1, -1, 1};
PLL c[4];
void solve()
{
    cin >> n >> x1 >> y1;
    for (int i = 0; i < 4; i++)
    {
        c[i].first = x1 + dx[i], c[i].second = y1 + dy[i];
    }
    cout << "Yes" << endl;
    if (n - 1 == 0)
    {
        cout << 0 << endl;
        return;
    }
    cout << n - 1 << endl;
    for (int i = 1; i <= n - 1; i++)
    {
        if (c[0].first >= 1 && c[0].second >= 1)
        {
            cout << c[0].first << ' ' << c[0].second << ' ' << c[1].first - c[0].first - 1 << ' ' << c[1].second - c[0].second - 1 << endl;
            c[0].first -= 1, c[0].second -= 1;
            c[2].second -= 1;
            c[3].first -= 1;
        }
        else if (c[1].first <= n && c[1].second <= n)
        {
            cout << c[1].first << ' ' << c[1].second << ' ' << c[0].first - c[1].first + 1 << ' ' << c[0].second - c[1].second + 1 << endl;
            c[1].first += 1, c[1].second += 1;
            c[2].first += 1;
            c[3].second += 1;
        }
        else if (c[2].first <= n && c[2].second >= 1)
        {
            cout << c[2].first << ' ' << c[2].second << ' ' << c[3].first - c[2].first + 1 << ' ' << c[3].second - c[2].second - 1 << endl;
            c[2].first += 1, c[2].second -= 1;
            c[0].second -= 1;
            c[1].first += 1;
        }
        else if (c[3].first >= 1 && c[3].second <= n)
        {
            cout << c[3].first << ' ' << c[3].second << ' ' << c[2].first - c[3].first - 1 << ' ' << c[2].second - c[3].second + 1 << endl;
            c[3].first -= 1, c[3].second += 1;
            c[0].first -= 1;
            c[1].second += 1;
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