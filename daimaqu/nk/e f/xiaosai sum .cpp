#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;

int n,m;
bool st[N];
int p[N],cnt,f[N];

ll q(ll  a,ll  b)
{
  int res=1;
  while(b)
  {
    if(b&1) res=(a*res)%mod;
    b>>=1;
    a=(a*a)%mod;

  }

  return res%mod;
}
void solve()
{
  cin>>n>>m;

  int res=1;
  for(int i=2;i<=n;i++)
  {
    if(!st[i]) p[++cnt] = i,f[i]=q(i,m);
    for(int j=1;p[j]*i<=n;j++)
    {
      st[i*p[j]] = true;
      f[i*p[j]]=(f[i]*f[p[j]])%mod;
      if(i%p[j]==0) break;
    }

    res=(f[i]+res)%mod;

  }  

  cout<<res<<endl;
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