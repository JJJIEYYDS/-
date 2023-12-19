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
string s;

void solve()
{
    cin >> s;
    s = '0' + s;
    int t = INF;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] - '0' >= 5)
        {
            int j = i - 1;
            while (j >= 0 && (s[j] - '0') + 1 >= 5)
            {
                j--;
            }

            t = j;
            s[t] = s[t] - '0' + 1 + '0';
            break;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0' && i == 0)
            continue;
        if (i <= t)
            cout << s[i];
        else
            cout << 0;
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