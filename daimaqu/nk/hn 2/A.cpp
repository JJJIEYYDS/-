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

ll a[N],b[N],s[N],c[N];

void solve()
{
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
         s[i]=s[i-1]+a[i];
    }

    for(int i=1;i<=n;i++) cin>>b[i];
    
    c[1]=1;
    
    for(int i=1;i<=n;i++)
    {
        if(b[i]>b[max(i-k+1,(ll)1)])
        {
            int j=max(i-k+1,(ll)1);
            int t=b[max(i-k+1,(ll)1)];
            while(b[j]==t)
            {
                j++;
            }
            c[i]=c[j-1];
        }
        else c[i]=max((ll)1,i-k+1);
        
    }

    while(m--)
    {
        ll x;
        cin>>x;
        ll ans = s[x]-s[c[x]-1];
        
        cout<<ans<<endl;
    }

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