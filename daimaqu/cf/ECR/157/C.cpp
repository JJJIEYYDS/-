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
string s[N];
bool cmp(string a, string b)
{
    return a.size() < b.size();
}

ll toshu(string s)
{
    ll res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res += (s[i] - '0');
    }
    return res;
}

void solve()
{
    cin >> n;
    ll ans = n;

    map<ll, ll> mp1, mp2, mp3, mp4, mp5;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        ll t = toshu(s[i]);

        if (s[i].size() % 2 == 0)
        {

            if (s[i].size() == 2)
            {
                ans += 2 * mp1[t];
                mp1[t] += 1;
            }
            else
            {
                ll t1 = t - (s[i][0] - '0') - (s[i][0] - '0');
                ll t2 = t - (s[i][s[i].size() - 1] - '0') - (s[i][s[i].size() - 1] - '0');
                if (t1 > 0)
                    ans += mp1[t1];
                if (t2 > 0)
                    ans += mp1[t2];
                ans += 2 * mp2[t];
                mp2[t] += 1;
            }
        }
        else
        {

            if (s[i].size() == 1)
            {
                ans += 2 * mp3[t];
                mp3[t] += 1;
            }
            else if (s[i].size() == 3)
            {
                ll t1 = t - (s[i][0] - '0') - (s[i][0] - '0');
                ll t2 = t - (s[i][s[i].size() - 1] - '0') - (s[i][s[i].size() - 1] - '0');
                if (t1 > 0)
                    ans += mp3[t1];
                if (t2 > 0)
                    ans += mp3[t2];
                ans += 2 * mp4[t];
                mp4[t] += 1;
            }
            else
            {
                ll t1 = t - (s[i][0] - '0') - (s[i][0] - '0');
                ll t2 = t - (s[i][4] - '0') - (s[i][4] - '0');
                ll t3 = t - (s[i][0] - '0') - (s[i][1] - '0') - (s[i][0] - '0') - (s[i][1] - '0');
                ll t4 = t - (s[i][4] - '0') - (s[i][3] - '0') - (s[i][4] - '0') - (s[i][3] - '0');
                if (t1 > 0)
                    ans += mp4[t1];
                if (t2 > 0)
                    ans += mp4[t2];
                if (t3 > 0)
                    ans += mp3[t3];
                if (t4 > 0)
                    ans += mp3[t4];
                ans += 2 * mp5[t];
                mp5[t] += 1;
            }
        }
    }
    cout << ans << endl;
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