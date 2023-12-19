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

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;
string a, b;

void solve()
{
    cin >> a >> b;
    map<char, ll> mp1, mp2, mp;
    for (int i = 1; i <= 7; i++)
    {
        char j = ('2' + i);

        mp[j] = i;
        // cout << j << ' ' << mp[j] << endl;
    }
    mp['X'] = 8;
    mp['J'] = 9;
    mp['Q'] = 10;
    mp['K'] = 11;
    mp['A'] = 12;
    mp['2'] = 13;
    mp['M'] = 14;
    mp['F'] = 15;
    ll t1 = 0, t2 = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t1 = max(mp[a[i]], t1);
        mp1[a[i]]++;
    }
    for (int i = 0; i < b.size(); i++)
    {
        t2 = max(t2, mp[b[i]]);
        mp2[b[i]]++;
    }
    if (mp1.size() == 1 || (mp1.find('M') != mp1.end() && mp1.find('F') != mp1.end()))
    {
        cout << "ShallowDream" << endl;
    }
    else if (t1 >= t2)
    {
        if ((mp2.find('M') != mp2.end() && mp2.find('F') != mp2.end()))
        {
            cout << "Joker" << endl;
        }
        else
            cout << "ShallowDream" << endl;
    }
    else
    {
        cout << "Joker" << endl;
    }
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