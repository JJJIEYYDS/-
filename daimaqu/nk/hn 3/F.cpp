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

ll n,m,k;

ll ksm(ll a,ll b, ll p=mod)
{
    ll res=1;
    while(a)
    {
        if(b&1) res=(res*a)%p;
        b>>=1;
        a=(a%p*a%p)%p;
    }

    return res%p;
}
ll inv(ll x)
{
    return ksm(x,mod-2);
}
void solve()
{
    cin>>n>>m;
    m%=mod;

    if(m==1)
    {
        cout<<ksm(2,n+1)%mod<<endl;
    }
    else
    {
        ll t1=inv(m-1);
        ll res=ksm(2,n+1,mod-1);

        cout<<((ksm(m,res)-1+mod)%mod)*t1%mod<<endl;

    }
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