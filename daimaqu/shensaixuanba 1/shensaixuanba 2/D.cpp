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
const int N=1e6+10,INF=0x3f3f3f3f;

int n,m,k;
int p[N],s[N];
bool st[N];

int find(int x)
{
    if(x!=p[x]) 
    {
        p[x]=find(p[x]);
    }//不需要在这更新
    return p[x];
}
void solve()
{
    cin>>n>>m;

    for(int i=1;i<=3*n;i++)
    {
        p[i]=i;
        s[i]=1;
    }

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        int pa = find(a),pb = find(b);
        if(pa!=pb)
        {
            p[pa]=pb;
            s[pb]+=s[pa];
        } 
    }
    ll ans=0;
    for(int i=1;i<=3*n;i++)
    {
        int pi=find(i);
        //cout<<pi<<endl;
        if(!st[pi])
        {
            int t = s[pi];
            st[pi] =true;
            t%=3;

            if(t==1)
            {
                ans+=t*2;
            }
            else if(t==2)
            {
                ans+=t;
            }
        }

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