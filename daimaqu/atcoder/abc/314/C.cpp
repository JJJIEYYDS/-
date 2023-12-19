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
    cin >> n >> m;
    cin >> s;
    s = ' ' + s;
    vector<vector<int>> a(m + 1);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        c[i] = x;
        a[x].push_back(i);
    }

    for (int i = 1; i <= m; i++)
    {
        int t = a[i].back();
        a[i].pop_back();
        reverse(a[i].begin(), a[i].end());
        a[i].push_back(t);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << s[a[c[i]].back()];

        a[c[i]].pop_back();
    }
    cout << endl;
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