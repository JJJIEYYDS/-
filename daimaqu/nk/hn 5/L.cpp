#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <bitset>
using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
// a[i]^a[j]==2(a[i]&a[j])
// i为a[i]第i位，满足ai^bi==ai-1&bi-1,转化ai=(ai-1&bi-1)^bi
void solve()
{
    cin >> n;
    vector<ll> a(n + 1);
    map<ll, ll> mp;
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        bitset<63> b(a[i]); // 将它转化为0，1，总长为63
        ll w = 0, t = 0;
        for (int j = 0; j < 63; j++)
        {
            t ^= b[j];
            w += (t << j);
            t &= b[j];
        }
        if (mp.find(w) != mp.end() && !flag)
        {
            flag = true;
            cout << mp[w] << ' ' << i << endl;
        }
        mp[a[i]] = i;
    }
    if (!flag)
        cout << "-1" << endl;
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