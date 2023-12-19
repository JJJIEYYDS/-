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
const int N=1e3+10,INF=0x3f3f3f3f;

int n,m,k,d;

string s[N];

bool check(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(s[i][x]!='o') return false;
    }
    return true;
}
void solve()
{
    cin>>n>>d;

    for(int i=1;i<=n;i++)
    {
         cin>>s[i];
    }
    ll res=0,ans=0;
    for(int i=0;i<d;i++)
    {
        if(check(i))
        {
            res++,ans=max(ans,res);
        }
        else res=0;
    }
    ans=max(ans,res);

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