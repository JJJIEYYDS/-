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
const int N = 3e5 + 10, INF = 0x3f3f3f3f;

int n, m, k;
struct node
{
    int a, b, c;
} h[N];

bool cmp(node a, node f)
{
    if (a.a == f.a)
    {
        if (a.b == f.b)
            return a.c > f.c;
        return a.b > f.b;
    }
    return a.a > f.a;
}

void solve()
{
    cin >> n;
    int t[4] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> t[1] >> t[2] >> t[3];
        sort(t + 1, t + 3 + 1, greater<int>());
        h[i].a = t[1], h[i].b = t[2], h[i].c = t[3];
    }
    sort(h + 1, h + n + 1, cmp);
    bool flag = false;
    int t1 = 0, t2 = 0, t3 = 0;
    t1 = h[1].b, t2 = h[1].c;
    for (int i = 2; i <= n; i++)
    {
        if ((h[i].b < t1))
        {
            if (h[i].c < t2)
                flag = true;
        }
        else if (h[i].b > t1)
        {
            t1 = h[i].b, t2 = h[i].c;
        }
    }
    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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