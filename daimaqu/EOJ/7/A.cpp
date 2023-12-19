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

ll ksm(ll a,ll b,ll p=mod)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a)%p;
        b>>=1;
        a=(a%p*a%p)%p;
    }
    return res%p;
}


void solve()
{
    ll n;
    cin>>n;
    
    ll t1=n%mod;
    if(n==2)
    {
        cout<<7<<endl;
        return ;
    }
    
    ll t = (ksm(t1,n%(mod-1)+mod-1)%mod-(t1-1)+mod)%mod;


    cout<<t%mod<<endl;

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