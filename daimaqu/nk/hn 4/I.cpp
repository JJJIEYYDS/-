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
const int N=1e6+10,INF=0x3f3f3f3f,mod=998244353;

ll n,m,k,q;

struct node
{
    int x,y;
    bool operator<( const node &t ) const
    {
        return y<t.y;
    }
}h[N];

void solve()
{
    cin>>n;//右端点刚好能解决左端点问题

    for(int i=1;i<=n;i++)
    {
        cin>>h[i].x>>h[i].y;
    }

    sort(h+1,h+1+n);

    int t=-1;
    ll ans=0;
    int l=-1;
    for(int i=1;i<=n;i++)
    {
        if(h[i].x<=t) continue;
        if(h[i].x<=l)
        {
            ans++;
            t=h[i].y;
        }
        else l=h[i].y;
    }
    cout<<ans<<endl;
    

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