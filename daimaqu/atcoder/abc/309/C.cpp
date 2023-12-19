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
const int N=3e5+10,INF=0x3f3f3f3f;

int n,m,k;

vector<pair<ll,ll>> p;

void solve()
{
    cin>>n>>k;

    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        p.push_back({a,b});
        res+=b;
    }
    
    if(res<=k) 
    {
        cout<<1<<endl;
        return ;
    }
    sort(p.begin(),p.end());

    for(int i=0;i<n;i++)
    {
        
        res-=p[i].second;
         if(res<=k)
        {
            cout<<p[i].first+1<<endl;
            return ;
        }
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