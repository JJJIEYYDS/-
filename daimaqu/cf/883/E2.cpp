#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const long long N=1e18,INF=0x3f3f3f3f;

long long n,m,k;

map<ll,ll> mp;

void init()
{
   for(ll i=2;i<=1e6;i++)
    {
        __int128 res=1+i+i*i,cnt=i*i*i;
        while(res<=N)
        {
            mp[res]=1;
            res+=cnt;
            cnt*=i;
        }
   }
   
}
bool check(long long mid)
{
    return (1+mid+mid*mid)>=n;
}
void solve()
{
    cin>>n;
    
    if(mp.count(n))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        long long l=2,r=1e9;
        while(l<r)
        {
            long long mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        if(1+l+l*l==n) 
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    

}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;

    init();
    while(t--)
      solve();

    system("pause");
    return 0;
}