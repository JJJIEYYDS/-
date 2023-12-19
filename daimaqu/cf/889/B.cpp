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
const ll N=4e3+10,INF=0x3f3f3f3f,mod=998244353;

ll n,m,k;

void solve()
{
    cin>>n;
    vector<int> a;

    for(int i=1;i<=min(n,N);i++)
    {
        if(n%i==0) 
        {
            a.emplace_back(i);
        }
    }
    ll res=1,ans=1;
    for(int i=0;i<a.size();i++)
    {
        if(a[i+1]-a[i]==1)
        {
            res++;
        }
        else 
        {
            ans=max(res,ans);
            res=0;
        }
    }

    cout<<ans<<endl;
    a.clear();

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