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

int f(int a)
{
    int cnt=0;
    while(a)
    {
        cnt++;
        a/=10;
    }
    return cnt;
}
void solve()
{
    cin>>n;
    priority_queue<int> p1,p2;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        p1.push(x);
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        p2.push(x);
    }
    ll ans=0;
    while(1)
    {
        if(!p1.size()) break;
        int t1=p1.top();
        int t2=p2.top();
        if(t1==t2)
        {
            p1.pop();
            p2.pop();
        }
        else if(t1>t2)
        {
            ans++;
            p1.pop();
            p1.push(f(t1));
        }
        else
        {
            ans++;
            p2.pop();
            p2.push(f(t2));
        }
    }
    cout<<ans<<endl;

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