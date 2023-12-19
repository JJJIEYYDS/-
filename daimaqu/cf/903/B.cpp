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
    vector<ll> a(4);
    for (int i = 1; i <= 3; i++)
    {
        cin >> a[i];
    }
    priority_queue<ll> p;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 1; i <= 3; i++)
    {
        p.push(a[i]);
        q.push(a[i]);
    }
    n = 3;
    while (n--)
    {
        ll t1 = p.top();
        p.pop();
        ll t2 = q.top();
        q.pop();
        if (t1 != t2)
        {
            p.push(t1 - t2);
            p.push(t2);
            p.push(t2);
            q.push(t1 - t2);
            q.push(t2);
            q.push(t2);
        }
        else
            break;
    }
    ll t = p.top();
    while (p.size())
    {
        ll t3 = p.top();
        p.pop();
        if (t3 != t)
        {
            cout << "NO" << endl;
            return;
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