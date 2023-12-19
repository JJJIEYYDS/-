#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cmath>

using namespace std;

typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;
typedef long long ll;
const int N=1000,INF=0x3f3f3f3f,mod=998244353;

ll n,m,k,h;
ll a[N];

bool check(ll x)
{
    __int128 res=0;
    for(int i=1;i<n;i++)
    {
        if(a[i+1]<=(a[i]+x))
        {
            res+=(a[i+1]-a[i]);
        }
        else
        {
            res+=x;
        }
    }
    res+=x;
    return res>=h;
}

void solve()
{
    cin>>n>>h;
    a[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    ll l=1,r=1e18;
    while(l<r)
    {
        ll mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;


}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;

    while(t--)
      solve();

    system("pause");
    return 0;
}