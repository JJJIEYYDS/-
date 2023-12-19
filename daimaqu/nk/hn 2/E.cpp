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
const int N=1e6+10,INF=0x3f3f3f3f;

ll n,m,k;

ll a[N],s[N],c[N];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++) cin >> a[i];

    for(ll i=1;i<=n;i++)
    {
        c[max(i-a[i],(ll)1)]+=1;
        c[i]-=1;

        c[i+1]+=1;
        c[min(n,i+a[i])+1]-=1;
    }

    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+c[i];
    }

    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]>0) res++;
    }

    cout<<res<<endl;

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