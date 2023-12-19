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

ll c[35];

void init()
{
    c[1]=2;
    for(int i=2;i<=35;i++)
    {
        c[i]=c[i-1]*2;
    }
}

ll qs(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a;
        b>>=1;
        a*=a;
    }
    return res;
}
ll qs(ll a,ll b,ll p)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a)%p;
        b>>=1;
        a=(a*a)%p;
    }
    return res;
}

void solve()
{
    init();
    ll a,p;
    cin>>a>>p;
    ll sum=0;
    for(int i=1;i<=c[p];i++)
    {
        if(qs(a,i)==(qs(i,a,p)%c[p]))
        {
             cout<<i<<' ';
             sum++;
        }
    }
    cout<<endl;
    cout<<sum<<endl;
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