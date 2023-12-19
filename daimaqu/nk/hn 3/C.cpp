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
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;

ll check(ll x)
{
    ll cnt1=0,cnt2=0;
    for(int i=1;i<=x/i;i++)
    {
        if(x%i==0)
        {
            cnt1++;
            if(x/i!=i) cnt1++;
        }
    }

    for(int i=1;i<=(n-x)/i;i++)
    {
        if((n-x)%i==0)
        {
            cnt2++;
            if((n-x)/i!=i) cnt2++;
        }
    }

    return cnt1*cnt2;
}
void solve()
{
    cin>>n;
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        ans+=check(i);
    }

    cout<<ans<<endl;
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