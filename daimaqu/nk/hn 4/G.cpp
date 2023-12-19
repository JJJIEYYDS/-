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
const int N=1e5+10,INF=0x3f3f3f3f,mod=1e9+7;
ll fac[N],invfac[N],inv[N];

int n,m,k;
void init()
{
    inv[1]=invfac[1]=invfac[0]=fac[0]=fac[1]=1;
    for(int i=2;i<N;i++)
    {
       inv[i]=(1ll*mod-1ll*mod/i)*inv[mod%i]%mod;
       fac[i]=(fac[i-1]*(i))%mod;
       invfac[i]=(invfac[i-1]*inv[i])%mod;        
    } 
}

ll c(ll n,ll m)
{
    if(m>n) return 0;
    return (fac[n]*invfac[m])%mod*invfac[n-m]%mod;
}

void solve()
{
    cin>>n>>k;
    map<int,int> mp;
    vector<int> p;
    ll dis=-1;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(mp[x])
        {
            dis=i-mp[x];
        }
        else
        {
            mp[x]=i;
        }
    }

    if(dis==-1)
    {
        cout<<c(n,k)%mod<<endl;
    }
    else
    {
        cout<<(c(n,k)-c(n-dis-1,k-1)+mod)%mod<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    init();
    while(t--)
      solve();

    system("pause");
    return 0;
}