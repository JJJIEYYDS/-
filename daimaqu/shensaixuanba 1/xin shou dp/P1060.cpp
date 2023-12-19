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

int n,m,k;

ll v[50],w[50];

ll dp[50000];//

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        cin>>v[i]>>w[i];
       
    }

   for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=v[i];j--)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]*v[i]);
        }
    }

    cout<<dp[n]<<endl;
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