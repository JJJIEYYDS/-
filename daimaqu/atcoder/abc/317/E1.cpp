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
vector<int> v[N];
bool st[N], st1[N];
map<ll, vector<ll>> mp2;
map<ll, ll> mp1;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            int y;
            cin >> y;
            mp1[i]++;
            v[i].push_back(y);
            mp2[y].push_back(i);
        }
    }
    priority_queue<PLL, vector<PLL>, greater<PLL>> p;
    queue<ll> q;
    q.push(1);
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        if (st[t])
            continue;
        st[t] = true;
        for (auto x : v[t])
        {
            p.push({mp1[x], x});
            q.push(x);
        }
    }
    while (p.size())
    {
        auto t = p.top();
        p.pop();
        if (st1[t.second])
            continue;
        if (t.first <= 0)
        {
            if (t.second == 1)
            {
                return;
            }
            if (t.second > 1 && !st1[t.second])
            {
                st1[t.second] = true;
                cout << t.second << ' ';
            }
            for (auto x : mp2[t.second])
            {
                if (mp1[x] > 0&&st[x])
                    mp1[x]--, p.push({mp1[x], x});
            }
            continue;
        }
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