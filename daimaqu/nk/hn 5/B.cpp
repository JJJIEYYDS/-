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
    cin >> n;
    set<string> st;
    string s1 = "sudo pacman -S ", s2 = "pacman -R ", s3 = "pacman -Rscn ";
    string t = "sudo rm -rf /*";
    for (int i = 1; i <= n + 1; i++)
    {
        string s;
        getline(cin, s);
        if (s == t)
        {
            cout << "wuwuwu" << endl;
            return;
        }
        if (s[0] != '2' && s[0] != '1')
            st.insert(s);
        else
        {
            string t1;
            for (int i = 2; i < s.size(); i++)
                t1 += s[i];
            if (s[0] == '1')
            {

                if (st.find(s1 + t1) != st.end() && st.find(s2 + t1) == st.end() && st.find(s3 + t1) == st.end())
                {
                    cout << "yes" << endl;
                }
                else
                    cout << "no" << endl;
            }
            else
            {
                if (st.find(s1 + t1) != st.end() && st.find(s3 + t1) == st.end())
                {
                    cout << "yes" << endl;
                }
                else
                    cout << "no" << endl;
            }
        }
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