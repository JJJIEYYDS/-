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
    vector<ll> a(m), b(n), c(n);
    vector<string> s(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        b[i] += (i + 1);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'o')
            {
                b[i] += a[j];
            }
        }
    }
    c = b;
    sort(b.begin(), b.end(), greater<ll>());

    for (int i = 0; i < n; i++)
    {
        vector<ll> v;
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'x')
                v.push_back(a[j]);
        }
        sort(v.begin(), v.end(), greater<ll>());
        ll t1 = 0, t2 = c[i];
        if (c[i] == b[0])
        {
            cout << 0 << endl;
            continue;
        }
        for (auto x : v)
        {
            t1++;
            if (t2 + x > b[0])
            {
                cout << t1 << endl;
                break;
            }
            else
            {
                t2 += x;
            }
        }
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