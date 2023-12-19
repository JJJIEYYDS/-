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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
int a[N], sum[N];

void solve()
{
    cin >> n;
    vector<int> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[a[i]]++;
    }
    for (int i = n; i >= 1; i--)
    {
        while (sum[i])
        {
            int cnt = 0;
            for (int j = i; j >= 1; j--)
            {
                sum[j]--;
                cnt++;
                if (sum[j] + 1 > sum[j - 1])
                    // 此时sum[j]需要断开，从前以i结尾，又以它开头，才能保证有答案
                    break;
            }
            if (cnt < 5)
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