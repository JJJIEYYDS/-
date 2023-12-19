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
const int N=1e3+10,INF=0x3f3f3f3f;

int n,m,k;

ll a[N];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    ll ans=1e9;

    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i+1])
        {
            cout<<0<<endl;
            return ;
        }
        if(a[i]==a[i+1])
        {
             ans=min(ans,(ll)1);
             continue;
        }

        if((a[i+1]-a[i])%2!=0) 
        {
            ans=min(ans,(a[i+1]-a[i]+1)/2);
        }
        else 
        {
            ans=min(ans,(a[i+1]-a[i])/2+1);
        }
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