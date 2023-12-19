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

int n,m,k;
vector<int> a;
ll dp[20][20][10];
ll dp1[20][20][2];

ll top;


ll dfs(ll pos, ll num, bool limit, int cnt)
{
    if(!pos) return cnt;
    if(~dp[pos][cnt][num]&&!limit) return dp[pos][cnt][num];

    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;i++)
    {
        ans+=dfs(pos-1,num,limit&&(i==up),cnt+(i==num));
    }
    if(!limit) dp[pos][cnt][num]=ans;
    return ans;
}

void get(ll x)
{
    a.clear();
    top=0;
    while(x)
    {
        a[++top]=x%10;
        x/=10;
    }
}

ll dfs1(int pos, int num,bool limit,bool have)
{
    if(!pos) return have;
    if(~dp1[pos][num][have]&&!limit) return dp1[pos][num][have];

    int up =  limit?a[pos]:9;
    ll ans=0;
    ll t=0;
    for(int i=0;i<=up;i++)
    {
        t=num;
        if(i==7)  
        {
            t++;
            ans+=dfs1(pos-1,t,limit&&(i==up),have||t>=7);
        }
        else 
        {
            t=0;
            ans+=dfs1(pos-1,t,limit&&(i==up),have||t>=7);
        }
    }
    if(!limit) dp1[pos][num][have]=ans;
    return ans;
}

ll count(ll x)
{
    ll ans=0;
    get(x);
    ans=dfs(top,7,true,0)*3+dfs(top,5,true,0);
    ans+=300*dfs1(top,0,true,false);
    return ans;
    
}

void solve()
{
    ll l,r;
    cin>>l>>r;

    cout<<count(r)-count(l-1)<<endl;

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