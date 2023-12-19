#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=2e5+10,INF=0x3f3f3f3f;

int n,m,k;

ll dp[N];
ll a[N];

void solve()
{
    cin>>n;
    ll res=-1e9;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    if(n==1) 
    {
        cout<<a[1]<<endl;
        return;
    }
    dp[1]=a[1];
        
    dp[2]=a[2];

    for(int i=3;i<=n;i++)
    {
        dp[i]=max(a[i],max(dp[i-2]+a[i],dp[i-2]));//9 1 -1 2 2可以省略掉-1，把dp[3]=d[1];
        
    }
    for(int i=1;i<=n;i++)
    {
        res=max(dp[i],res);
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