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
const int N = 2e3 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
ll cntx[30][N], cnty[30][N];
ll resx[N], resy[N];

void solve()
{
  cin >> n >> m;
  ll ansx = n, ansy = m;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      char c;
      cin >> c;
      cntx[c - 'a'][i]++;
      cnty[c - 'a'][j]++;
    }
  }

  for (int i = 1; i <= n; i++)
    resx[i] = m;
  for (int i = 1; i <= m; i++)
    resy[i] = n;

  for (int i = 1; i <= n + m; i++)
  {
    vector<PLL> delx, dely;
    for (int j = 1; j <= n; j++)
    {
      if (!resx[j])
        continue;
      for (int k = 0; k <= 25; k++)
      {
        if (cntx[k][j] == resx[j] && resx[j] > 1)
        {
          ansx--;
          resx[j] = 0;
          cntx[k][j] = 0;
          delx.push_back({j, k});
        }
      }
    }
    for (int j = 1; j <= m; j++)
    {
      if (!resy[j])
        continue;
      for (int k = 0; k <= 25; k++)
      {
        if (cnty[k][j] == resy[j] && resy[j] > 1)
        {
          ansy--;
          resy[j] = 0;
          cnty[k][j] = 0;
          dely.push_back({j, k});
        }
      }
    }
    for (auto [x, y] : delx)
    {
      for (int j = 1; j <= m; j++)
      {
        resy[j]--, cnty[y][j]--;
      }
    }
    for (auto [x, y] : dely)
    {
      for (int j = 1; j <= n; j++)
      {
        resx[j]--, cntx[y][j]--;
      }
    }
  }

  cout << ansx * ansy << endl;
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