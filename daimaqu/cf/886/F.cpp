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
const int N=2e5+10,INF=0x3f3f3f3f;

int n,m,k;

int dp[N];
int a[N];
void solve()
{
    cin>>n;
    map<ll,ll> mp,mp1;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>n) continue;
        else 
        {
            mp[x]+=1;
        }
    }

    for(auto x:mp)
    {
        ll t=x.first;
        //cout<<x.first<<' ';
        while(t<=n)
        {
            mp1[t]+=x.second;
            t+=x.first;
        }
    }
    ll res=0;
    for(auto x:mp1)
    {
        res=max(res,x.second);
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