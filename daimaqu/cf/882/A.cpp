#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<cmath>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;
int a[110],s[110];

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int res=0;

    for(int i=1;i<=n-1;i++)
    {
        s[i]=abs(a[i]-a[i+1]);
        res+=s[i];

    }
    sort(s+1,s+n,greater<int>());

    for(int i=1;i<=k-1;i++)
    {
        res-=s[i];
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