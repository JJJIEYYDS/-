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
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;

ll a[N];

bool check(int x)
{
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=x) continue;
        res+=((a[i]-x)*2);
    }
    return res>=m;
}
void solve()
{
    cin>>n>>m;
    ll res=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        res+=(2*a[i]);
    } 

    if(res<m) 
    {
        cout<<-1<<endl;
        return ;
    }
    sort(a+1,a+n+1);

    int l=a[1],r=a[n];
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }

    cout<<l<<endl;

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