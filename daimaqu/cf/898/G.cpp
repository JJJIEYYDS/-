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
    int cnta = 0, cntb = 0;
    int t1 = 0, t2 = 0;
    vector<int> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
        {
            t1++;
            if (t2 == 1)
                cntb++;
            else if (t2 >= 2)
                cntb += 2;
            t2 = 0;
        }
        else
        {
            if (t1)
                cnta++;
            v.push_back(t1);
            t1 = 0;
            t2++;
        }
    }
    if (t1)
        v.push_back(t1), cnta++;
    if (t2 == 1)
        cntb++;
    else if (t2 >= 2)
        cntb += 2;
    if (cnta <= cntb)
    {
        ll ans = 0;
        for (auto x : v)
        {
            ans += x;
        }
        cout << ans << endl;
    }
    else
    {
        sort(v.begin(), v.end(), greater<ll>());
        ll ans = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            ans += v[i];
        }
        cout << ans << endl;
    }
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