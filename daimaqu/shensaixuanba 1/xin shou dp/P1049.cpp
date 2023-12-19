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
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k,v;

ll a[50];
ll dp[N];
void solve()
{

    cin >> m >> n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
       for(int j=m;j>=a[i];j--)
       {

        dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
         
       }
    }

    cout<<m-dp[m]<<endl;
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