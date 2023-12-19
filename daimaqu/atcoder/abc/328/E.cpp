#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int N = 50;
typedef long long ll;

long long n, m, k;

struct edges
{
    long long a, b, w;
    bool operator<(const edges &p) const
    {
        return w < p.w;
    }
} e[N];

ll res = 0;
ll ans = 1e15;
bool st[N];
bool s[N];
ll cnt = 0;
ll v[N];

void dfs(int cnt, ll res)
{
    if (cnt >= n)
    {
        ans = min(res, ans);
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        ll u1 = e[i].a, v1 = e[i].b, w = e[i].w;

        if (!s[i])
        {
            // cout <<  << ' ' << i << endl;
            if (st[u1] && !st[v1])
            {
                s[i] = true;
                st[v1] = true;
                v[cnt] = i;
                dfs(cnt + 1, (res + w) % k);
                st[v1] = false;
                s[i] = false;
            }
            else if (!st[u1] && st[v1])
            {
                st[u1] = true;
                s[i] = true;
                v[cnt] = i;
                dfs(cnt + 1, (res + w) % k);
                st[u1] = false;
                s[i] = false;
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].a >> e[i].b >> e[i].w;
    }
    sort(e + 1, e + m + 1);

    st[1] = 1;
    dfs(1, 0);

    cout << ans << endl;

    system("pause");
    return 0;
}