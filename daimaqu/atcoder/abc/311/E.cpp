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
const int N=3010,INF=0x3f3f3f3f;

int n,m,k,u;

int a[N][N],s[N][N];

bool check(int i,int j, int x)
{
    if(x+i>n||j+x>m) return false; 
    if(s[i+x][j+x]-s[i+x][j-1]-s[i-1][j+x]+s[i-1][j-1]==0) return true;
    else return false;
}

void solve()
{
    cin>>n>>m>>u;

    for(int i=1;i<=u;i++)
    { 
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }

    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!a[i][j])
            {
                ans++;
                int l=0,r=min(n,m);
                while(l<r)
                {
                    int mid=(l+r+1)>>1;
                    
                    if(check(i,j,mid)) l=mid;
                    else r=mid-1;
                }
                ans+=l;
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