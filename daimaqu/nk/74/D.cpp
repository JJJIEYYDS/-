#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;

const int N=1e5+10,INF=0x3f3f3f3f;

int n,m;

ll a[N],b[N];

void solve()
{
    cin>>n>>m;
    
    ll res=0;
    
    memset(b,0,sizeof b);
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        res+=a[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)
        {
            b[i]=a[i]*(n-i+1);
        }
    }
    
    sort(b+1,b+n+1,greater<ll>());

    for(int i=1;i<=min(n,m);i++)
    {
        res-=b[i];
    }
    
    cout<<res<<endl;
    
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