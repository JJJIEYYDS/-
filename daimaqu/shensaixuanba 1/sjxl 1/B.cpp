#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=2e5+10,INF=0x3f3f3f3f;

int n,m,k;



int a[N],c[N],l[N],r[N],cnt,f[N];

int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int t)
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        c[i]=max(c[i],t);
    }
}

int query(int x)
{
    int mx=0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        mx=max(mx,c[i]);
    }
    return mx;
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!l[a[i]]) l[a[i]]=i,cnt++;
        r[a[i]]=i;
    }
    int mx=1;
    for(int i=1;i<=n;i++)
    {
        if(i==l[a[i]]) f[a[i]]=query(a[i]-1)+1;
        if(i==r[a[i]]) update(a[i],f[a[i]]);
        mx=max(f[a[i]],mx);
    }

    cout<<cnt-mx<<endl;
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