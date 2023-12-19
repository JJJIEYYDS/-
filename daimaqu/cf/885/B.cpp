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

int a[N];

void solve()
{
    cin>>n>>m;
    vector<vector<int> > v(m+1);

    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        v[x].push_back(i);
    }

    int res=1e9;
    for(auto x:v)
    {
        x.push_back(n+1);
        vector<int> g;
        g.push_back(x[0]-1);
        for(int i=1;i<x.size();i++)
        {
            g.push_back(x[i]-x[i-1]-1);
        }
        sort(g.begin(),g.end(),greater<int>());
        int y=max(g[0]/2,g[1]);
        res=min(res,y);
        
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