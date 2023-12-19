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
const int N=1e5+10,INF=0x3f3f3f3f,mod=998244353;

int n,m,k,q;
int p[N];

int get(int x)
{
    return x*x;
}

int dis(int x,int y,vector<array<int,3>> a)
{
    if(a[x][0]==a[y][0]&&a[x][1]==a[y][1]) return 0;
    if(!a[x][2]&&!a[y][2]) return INF;
    int v = a[x][2]+a[y][2];
    return (int)ceil(sqrt(get(a[x][0]-a[y][0])+get(a[y][1]-a[x][1]))/v);
}

int find(int x)
{
    if(x!=p[x])
    {
        p[x]=find(p[x]);
    }
    return p[x];
}



void solve()
{
    cin>>n;

    vector<array<int,3>> e;
    vector<array<int,3>> a(n+1);
    for(int i=1;i<=n;i++) p[i]=i;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            e.push_back({dis(i,j,a),i,j});
        }
    }
    sort(e.begin(),e.end());

    cin>>q;
    vector<PII> qe;
    vector<int> ans(q);

    for(int i=0;i<q;i++)
    {
        int t;
        cin>>t;
        qe.push_back({t,i});
    }

    sort(qe.begin(),qe.end());
    
    for(int i=0,j=0;i<q;i++)
    {
        while(j<(int)e.size()&&e[j][0]<=qe[i].first)
        {
            int px=find(e[j][1]),py=find(e[j][2]);
            if(px!=py)
            {
                p[px]=py,n--;
            }
            j++;
        }
        ans[qe[i].second]=n;
        
    }

    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<endl;
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