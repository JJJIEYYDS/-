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
const int N=3e5+10,INF=0x3f3f3f3f,mod=998244353;

int n,m,k;

ll x[N],y[N];

void solve()
{
    cin>>n>>m;
    vector<ll> a,b,c;

    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==2)
        {
            c.emplace_back(y);
        }
        else if(x==1)
        {
            b.emplace_back(y);
        }
        else 
        {
            a.emplace_back(y);
        }
    }

    sort(a.begin(),a.end(),greater<ll>());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    for(int i=1;i<=m;i++)
    {
        if(i<=a.size()) x[i]=x[i-1]+a[i-1];
        else x[i]=x[i-1];
    }

    int t=0;
    for(int i=1;i<=m;i++)
    {
        if(b.empty()) y[i]=y[i-1];
        else if(!t)
        {
            if(c.size())
            {
                t=c.back();
                c.pop_back();
            }
            y[i]=y[i-1];
        }
        else
        {
            t--;
            y[i]=y[i-1]+b.back();
            b.pop_back();
        }
    }

    ll ans=0;

    for(int i=0;i<=m;i++)
    {
        ans=max(ans,x[i]+y[m-i]);
    }

    cout<<ans<<endl;


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