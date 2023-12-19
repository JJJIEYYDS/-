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
    vector<int> a;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+')
        {
            if (a.size() == 0)
                a.push_back(1);
            else
                a.push_back(0);
        }
        else if (s[i] == '-')
        {
            if (a.back() == 1)
            {
                if (a.size() == 1)
                {
                }
                else
                {
                    a[a.size() - 2] = 1;
                }
            }
            if (a.back() == -1)
                cnt--;
            a.pop_back();
        }
        else if (s[i] == '1')
        {
            if (a.size() == 0)
                continue;
            else
            {
                a[a.size() - 1] = 1;
            }
            if (cnt > 0 && a.size() >= 2)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            if (a.size() > 1)
            {
                if (a.back() == 1)
                {
                    cout << "NO" << endl;
                    return;
                }
                int t = a.size();
                if (a[t - 1] == -1)
                    continue;
                a[t - 1] = -1;
                cnt++;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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