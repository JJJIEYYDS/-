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

void solve()
{
    cin>>n;
    int t=-1;
    vector<int> a(n+1);
    vector<PII> v;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(a[i]!=0)
        {
            t=i;
        }
    }

    if(t==-1)
    {
        cout<<0<<endl;
        return ;
    }

    for(int i=1;i<=5;i++)
    {
        a[t]+=a[t];
        v.emplace_back(t,t);
    }

    for(int i=1;i<=n;i++)
    {
        a[i]+=a[t];
        v.emplace_back(i,t);
    }
    if(a[t]>0)
    {
        for(int i=1;i<n;i++)
        {
            v.emplace_back(i+1,i);
        }
    }
    else 
    {
        for(int i=n;i>=2;i--)
        {
            v.emplace_back(i-1,i);
        }
    }

    cout<<v.size()<<endl;

    for(auto [x,y]:v)
    {
        cout<<x<<' '<<y<<endl;
    }

    v.clear();

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