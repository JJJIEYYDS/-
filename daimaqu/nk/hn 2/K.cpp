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

const int N=5e6+10,INF=0x3f3f3f3f;

int n,m,k;

ll a[N][6];
ll f(ll x,ll y)
{
    ll res=0;
    while(x%y==0)
    {
        x/=y;
        res++;
    }
    return res;
}

void init(ll n)
{
    a[0][2]=0,a[0][5]=0;
    a[1][2]=0,a[1][5]=0;
    for(int i=2;i<=n;i++)
    {
        a[i][2]=a[i-1][2]+f((4*i-2),2)-f(i+1,2);
        a[i][5] = a[i-1][5]+f((4*i-2),5)-f(i+1,5);
    }
}
void solve()
{
    
    cin>>n;
    init(n+2);
    ll cnt1=0,cnt2=0;
    for(int i=2;i<=n;i++)
    {
        cnt1+=a[i][2];
        cnt2+=a[i][5];
    }

    cout<<min(cnt1,cnt2)<<endl;

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