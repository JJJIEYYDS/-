#include <iostream>
#include <cstring>
#include <unordered_set>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
long long n, m;

vector<ll> s;
map<ll, ll> mp;

ll sg(ll x)
{
    if (mp.find(x) != mp.end())
        return mp[x];

    unordered_set<ll> S; // 进行哈希，即查找

    for (int i = 0; i < s.size(); i++)
    {
        ll sum = s[i];

        if (x >= sum)
            S.insert(sg(x - sum)); // 将每一个数，进行s[i]种操作
        // 最多将f[i]递变一遍，由于每次到达x时，之后结果都会确定
    }

    for (int i = 0;; i++)
    {
        if (!S.count(i))
            return mp[x] = i;
        // 进行mex操作，即找出最小的不属于S,中的自然数
    }
}

int main()
{
    // 将每一堆用s[i]展开，进行mex操作，求出每一顶点的sg值，
    // 然后进行一遍^操作，得到最终答案，
    cin >> n >> m;
    __int128 t = m;
    s.push_back(1);
    while (t <= 1e18 && m != 1)
    {
        s.push_back(t);
        t *= m;
    }

    ll res = 0; // 不影响

    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        res ^= sg(x);
        cout << sg(x) << endl;
    }

    cout << (res ? "GOOD" : "BAD") << endl; // 直接判别
    system("pause");
    return 0;
}