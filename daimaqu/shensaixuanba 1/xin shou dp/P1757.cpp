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

ll dp[1010];//前i组中总体积不超过j

void solve()
{
    cin >> m >> n;

    vector<vector<ll>> v(110),w(110);
    ll res = 0;

    for(int i=1;i<=n;i++)
    {
        ll x,y,z;
        cin >> x >> y >> z;

        v[z].push_back(x),w[z].push_back(y);
        res=max(res,z);
    }

    for(int i=1;i<=res;i++)
    {
        for(int j=m;j>=0;j--)
        {
            for(int k=0;k<v[i].size();k++)
            {
                if(j>=v[i][k])
                dp[j]=max(dp[j],dp[j-v[i][k]]+w[i][k]);
            }
        }
    }

    cout<<dp[m]<<endl;
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