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
    vector<int> a(n+1);
    ll cnt1=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==i) cnt1++;
    }
    cout<<(cnt1+1)/2<<endl;
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