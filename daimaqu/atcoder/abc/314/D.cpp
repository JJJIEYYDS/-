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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
string s;
struct node
{
    int b;
    char c;
} v[N];
int cnt;
void solve()
{
    cin >> n;
    cin >> s;
    s = ' ' + s;
    cin >> q;
    vector<int> a(q + 1);

    int res = 0;
    for (int i = 1; i <= q; i++)
    {
        int op, b;
        char d;
        cin >> op >> b >> d;
        a[i] = op;
        if (op == 1)
        {
            v[i] = {b, d};
        }
        else if (op == 2)
        {
            res = i;
        }
        else
        {
            res = i;
        }
    }

    for (int i = 1; i <= q; i++)
    {
        if (a[i] != 1 && i < res)
        {
            continue;
        }
        if (a[i] == 1)
            s[v[i].b] = v[i].c;
        else
        {
            if (a[i] == 2)
                for (int i = 1; i <= n; i++)
                {
                    if (s[i] >= 65 && s[i] <= 90)
                    {
                        s[i] = s[i] + 32;
                    }
                }
            else
            {
                for (int i = 1; i <= n; i++)
                {
                    if (s[i] >= 97 && s[i] <= 122)
                    {
                        s[i] = s[i] - 32;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << s[i];
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