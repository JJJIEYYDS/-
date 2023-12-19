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
const int N=100,INF=0x3f3f3f3f;

int n,m,k,h;

int a[N];

void solve()
{
    cin>>n>>m>>k>>h;
    set<ll> st;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<m;i++)
    {
        st.insert(i*k);
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(st.find(abs(h-a[i]))!=st.end()) ans++;
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