#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=60,INF=0x3f3f3f3f;

int n,m,t;


void solve()
{
    cin>>n>>t;

    vector<pair<ll,vector<ll>>> f(n+1);

    for(int i=1;i<=n;i++)
    {
        int x;

        cin>>f[i].first>>x;

        for(int j=0;j<x;j++)
        {
            int y;
            cin>>y;
            f[i].second.push_back(y);
        }
    }

    sort(f.begin(),f.end());

    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(f[i].first>t) break;

        ll now=t-f[i].first;

        vector<ll> temp;
        
        for(int j=1;j<=i;j++)
        {
            for(auto x:f[j].second)
            {
                temp.push_back(x);
            }
        }

        sort(temp.begin(),temp.end());

        ll res=0;
        for(int j=0;j<temp.size();j++)
        {
            if(now>=temp[j])
            {
                res++;
                now-=temp[j];
            }
            else break;
        }

        ans=max(ans,res);


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