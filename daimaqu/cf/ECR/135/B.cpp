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

ll n,m,k,q;
int a[N],cnt,b[N];
int x;
int z;
bool st[N];
void dfs(int u)
{
    if(u==n)
    {   
        x=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>x) x+=a[i];
            else x=0;
        }
        if(x>=z)
        {
            z=x;
            cout<<x<<endl;
            for(int i=0;i<n;i++)
            {
                b[i]=a[i];
                cout<<b[i]<<' ';
            }
            cout<<endl;
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            a[u]=i;
            st[i]=true;
            dfs(u+1);
            st[i]=false;
        }
    }
}
void solve()
{
    cin>>n;
    memset(st,0,sizeof st);
    z=0;
    dfs(0);

   
    cout<<endl;

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