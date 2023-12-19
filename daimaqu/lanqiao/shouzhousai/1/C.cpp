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
vector<ll> h;

bool check(int x)
{
    int cnt = 1, cur = h[1];
    for (int i = 2; i <= n; i++)
    {
        if (h[i] - cur > x)
        {
            cnt++;
            cur = h[i];
        }
    }
    // 没有等于x的也没关系，因为下一轮会变小，最终一轮，会达到最小的那个值
    return cnt <= k;
}

void solve()
{
    cin >> n >> k;
    h = vector<ll>(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    sort(h.begin() + 1, h.end());
    int l = 0, r = 1e9; // 最值问题先看是否是1.直接枚举答案（二分）
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
            l = mid + 1;
    }
    cout << l << endl;
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