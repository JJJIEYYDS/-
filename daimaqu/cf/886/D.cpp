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

int n,m,k;

void solve()
{
    cin>>n>>k;

    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    
    sort(v.begin(),v.end());
    int res=1,ans=0;
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i+1]-v[i]<=k) 
        {
            res++;
        }
        else
        {
            ans=max(res,ans);

            res=1;
        }
    }
    ans=max(ans,res);

    cout<<n-ans<<endl;
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