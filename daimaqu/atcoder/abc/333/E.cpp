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

void solve()
{
    cin >> n;
    vector<vector<ll>> a(n + 1);
    vector<ll> c(n + 1);
    vector<ll> sum(n + 2), sum1(n + 2);

    bool flag = false;
    vector<ll> v;
    set<ll> st;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;

        if (x == 1)
        {
            v.push_back(i);
            a[y].push_back(i);
        }
        else
        {
            if (a[y].size() == 0)
            {
                flag = true;
            }
            else
            {
                ll t = a[y].back();
                st.insert(t);
                a[y].pop_back();
                sum[t] += 1;
                sum[i + 1] -= 1;
            }
        }
    }
    ll ans = 0;
    if (flag)
    {
        cout << -1 << endl;
        return;
    }
    else
    {

        for (int i = 1; i <= n; i++)
        {
            sum1[i] = sum1[i - 1] + sum[i];
            ans = max(sum1[i], ans);
        }
        cout << ans << endl;
        for (auto x : v)
        {
            if (st.count(x))
            {
                cout << 1 << ' ';
            }
            else
            {
                cout << 0 << ' ';
            }
        }
        cout << endl;
    }
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