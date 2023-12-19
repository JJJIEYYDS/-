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


void solve()
{
    ll n,s;
    cin>>n>>s;
    if(s%n==0)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<s/n<<' ';
        }
        cout<<endl;
    }
    else
    {
        ll x=s%n;
        for(int i=1;i<=n-x;i++)
        {
            cout<<s/n<<' ';
        }
        for(int i=1;i<=x;i++)
        {
            cout<<s/n+1<<' ';
        }
        cout<<endl;
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