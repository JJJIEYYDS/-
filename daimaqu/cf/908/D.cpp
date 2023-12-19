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
    cin >> n >> m;
    vector<ll> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    vector<ll> ans;
    sort(b.begin() + 1, b.end());
    int j = 1;
    for (int i = n; i >= 1; i--)
    {
        while (j <= m && b[j] <= a[i])
        {
            ans.push_back(b[j]);
            j++;
        }
        ans.push_back(a[i]);
    }
    for (int i = j; i <= m; i++)
    {
        ans.push_back(b[i]);
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
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
    cin >> n;
    system("pause");
    return 0;
}