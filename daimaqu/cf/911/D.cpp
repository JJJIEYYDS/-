#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <array>

using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef unsigned long long ULL;
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
vector<vector<ll>> y(N + 10);

void init()
{
    for (int i = 1; i <= N; i++) // nlogn时间求出1~n中每一个数所有的因子
    {
        for (int j = i; j <= N; j += i)
        {
            y[j].push_back(i);
        }
    }
}
void solve()
{
    // 枚举a2我们只要知道a1,就可以知道答案，由于gcd,考虑所有因子
    //    6 6  6
    //      12 12
    // 实际6的贡献只有前面那一段，这个数应该去掉它后面倍数的值
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> res(N, 0), cnt(N, 0); // 存每一个因子的贡献和数量，res存的是长度
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++)
    {
        for (auto x : y[a[i]])
        {
            res[x] += cnt[x] * (n - i);
            cnt[x]++;
        }
    }
    ll ans = 0;
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + i; j < N; j += i)
        {
            res[i] -= res[j];
        }
        ans += i * res[i]; // 计算贡献
        // cout << ans << endl;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
        solve();

    system("pause");
    return 0;
}