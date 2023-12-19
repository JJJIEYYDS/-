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
const int N=1e3+10,INF=0x3f3f3f3f;

int n,m,k;

ll a[N],b[N],c[N];
ll dp[N];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }

    for(int i=1;i<=n;i++)
    {
       for(int j=m;j>=0;j--)
        {
            if(j>=c[i])
            {
                dp[j]=max(dp[j]+a[i],dp[j-c[i]]+b[i]);
            }
            else dp[j]=dp[j]+a[i];

        }
    }

    cout<<dp[m]*5<<endl;





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