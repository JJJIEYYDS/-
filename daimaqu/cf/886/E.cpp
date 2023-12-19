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
const int N=2e5+10,INF=0x3f3f3f3f;

ll n,m,k;

ll a[N];

bool check(__int128 x)
{
    __int128 res=0;
    for(int i=1;i<=n;i++)
    {
        res+=((a[i]+2*x)*(a[i]+2*x));
    }
    
    return res>=m;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    ll l=1,r=1e9;

    while(l<r)
    {
        __int128 mid=(l+r)>>1;
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