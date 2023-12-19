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
bool check(ll mid,vector<int> &a)
{
    for(int i=0;i<k;i++)
    {
        int x = lower_bound(a.begin(),a.end(),mid) - a.begin();//数组从零开始对应
        cout<<mid<<' '<<x<<endl;
        mid-=x;
        if(mid<=0) return false;
    }
    return true;
} 

void solve()
{
    cin>>n>>k;
    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll l=1,r=1e18;

    while(l<r)
    {
        ll mid=(l+r)>>1;
        if(check(mid,a)) r=mid;
        else l=mid+1;
    }

    cout<<l<<endl;


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