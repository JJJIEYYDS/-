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

int n,m,k,h;
int a[N],b[N];

bool cmp(PLL a,PLL b)
{
    return a.first>b.first;
}
void solve()
{
    cin>>n>>h;
    ll ans=0,t=0;
    vector<pair<ll,ll>> v(n+1);
    
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    
    sort(v.begin()+1,v.end(),cmp);
    ll temp=v[1].first;
    
    for(int i=1;i<=n;i++)
    {
        if(v[i].second>temp)
        {
            t++;
            ans+=v[i].second;
            if(ans>=h)
            {
                cout<<t<<endl;
                return ;
            }
        }
    }
    
    while(ans<h)
    {
        ans+=v[1].first;
        t++;
    }
    
    cout<<t<<endl;

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