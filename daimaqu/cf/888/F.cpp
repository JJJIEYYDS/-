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
const int N=1e5+10,INF=0x3f3f3f3f;

ll n,m,k;

void solve()
{
    cin>>n>>k;
    vector<PLL> v(n+1);

    ll x=(1<<k)-1;

    for(int i=1;i<=n;i++)
    {
        cin>>v[i].first;
        v[i].second=i;
    }

    sort(v.begin()+1,v.end());
    ll pos1=-1,pos2=-1;
    ll res=x+2,t=0;

    for(int i=1;i<n;i++)
    {
        auto [x,y]=v[i];
        auto t2=v[i+1];

        if((t1.first^t2.first)<res)
        {
            res=(t1.first^t2.first);
            pos1=t1.second,pos2=t2.second;
            t=t1.first&t2.first;
        }
        
    }
    
    cout<<pos1<<' '<<pos2<<' '<<x-t<<endl;


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