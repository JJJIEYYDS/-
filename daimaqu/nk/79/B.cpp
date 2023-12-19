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

typedef pair<int,int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
const int N=1e5+10, INF=0x3f3f3f3f, mod=998244353;

ll n,m,k,q;

void solve()
{
    cin >> n;
    vector<ll> a(n + 1);

    ll ans = 0;
    vector<ll> v;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
        if(a[i]%2==0)
        {
            ans += a[i];
        }
        else 
        {
            v.push_back(a[i]);
        }
    }

    if(v.size()%2==0)
    {
        for(auto x:v)
            ans += x;
    }
    else 
    {
        sort(v.begin() + 1, v.end(),greater<ll>());
        for (int i = 1; i < v.size()-1;i++)
        {
            ans += v[i];
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;

    while(t--)
      solve();

    system("pause");
    return 0;
}