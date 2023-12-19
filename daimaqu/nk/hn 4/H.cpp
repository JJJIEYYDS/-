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
const int N=1e5+10,INF=0x3f3f3f3f,mod=998244353;

ll n,m,k,q;
ll a[N],b[N];

bool check(int x)
{
    ll ans=0;
    ans=b[n];
    for(int i=n-1;i>=1;i--)
    {
        if(i==x) continue;
        ans=(ans+b[i])/2;
    }

    if(ans<=a[x]) return true;
    return false;
}
void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    
    int l=1,r=n;

    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    int x=b[l];

    for(int i=1;i<=n;i++)
    {
        if(a[i]>=x) cout<<1;
        else cout<<0;
    }

    cout<<endl;
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