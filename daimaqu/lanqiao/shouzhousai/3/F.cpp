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
vector<bool> isnotprime;
vector<int> primes, mindiv;
void getprime(int n)
{
    isnotprime.resize(n + 1, 0), mindiv.resize(n + 1, 1);
    isnotprime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (isnotprime[i] == 0)
        {
            primes.push_back(i);
            mindiv[i] = i;
        }
        for (size_t j = 0; j < primes.size() && i * primes[j] <= n; j++)
        {
            isnotprime[i * primes[j]] = 1, mindiv[i * primes[j]] = primes[j];
            if (i % primes[j] == 0)
                break;
        }
    }
}

const int maxn = 2e5 + 5;
int n, a[maxn], s, b, dis[maxn], f[maxn], isque[maxn];
vector<array<int, 2>> e[maxn];
void spfa(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    isque[s] = 1;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        isque[u] = 0;
        for (auto [v, w] : e[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!isque[v])
                {
                    isque[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
void solve()
{
    getprime(1e8);
    cin >> n >> s >> b;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int tmp = a[i];
        while (tmp > 1)
        {
            f[i] += mindiv[tmp], tmp /= mindiv[tmp];
        }
        f[i] = f[i] % n + 1;
        if (i != f[i])
            e[i].push_back({f[i], 1}), e[f[i]].push_back({i, 1});
    }
    for (int i = 1; i <= n; i++)
    {
        e[i].push_back({n + f[i], 1});
        e[n + f[i]].push_back({i, 0});
    }
    spfa(s);

    cout << (dis[n] == 0x3f3f3f3f ? -1 : dis[n]) << endl;
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