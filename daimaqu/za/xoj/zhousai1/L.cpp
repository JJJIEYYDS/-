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
const int N = 1010, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
string s[N];
string a[N], b[N];
ll p[N], si[N];
ll v[N];

ll find(int x)
{
    if (x != p[x])
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        si[i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        string t;
        for (auto &x : a[i])
        {
            t += tolower(x);
        }
        a[i] = "_";
        a[i] += t;
        a[i] += '_';
    }
    for (int i = 1; i <= m; i++)
    {
        string t;
        cin >> t;
        for (auto &x : t)
        {
            s[i] += tolower(x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ll pa = find(i), pb = find(j);
            if (b[i] == b[j])
            {
                if (pa != pb)
                {
                    p[pa] = pb;
                    si[pb] += si[pa];
                }
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        ll k = 0;
        for (int j = 1; j <= n; j++)
        {
            string t1 = '_' + s[i] + '_';
            if (a[j].find(t1) != -1)
                v[k++] = j;
        }
        // cout << v.size() << endl;
        if (k <= 1)
            continue;
        ll t = v[0];
        for (int u = 1; u < k; u++)
        {
            ll pa = find(v[u]), pb = find(t);
            if (pa != pb)
            {
                p[pa] = pb;
                si[pb] += si[pa];
            }
            t = v[u];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        ll pa = find(i);
        cout << si[pa] - 1 << endl;
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