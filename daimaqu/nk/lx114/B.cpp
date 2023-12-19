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
  ll a1, b1, c1, a2, b2, c2;
  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  ll res = a1 * b1 + a2 * b2 + a3 * b3;
  if (res == 100)
  {
    cout << "Sorry,NoBruteForce" << endl;
    return;
  }
  double ans = (double)1 / (1 - res);
  cout << fixed << setprecision(4) << ans << endl;
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