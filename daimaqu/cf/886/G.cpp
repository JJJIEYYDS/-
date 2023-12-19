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

void solve()
{
    cin>>n;
    vector<PLL> a(n);
    map<int,int> mp1,mp2,mp3,mp4;

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i].first=x,a[i].second=y;
        mp1[x]++,mp2[y]++,mp3[x+y]++,mp4[x-y]++;
    }

    ll ans=0;

    for(int i=0;i<n;i++)
    {
        int x=a[i].first,y=a[i].second;
        ans=ans+(mp1[x]-1)+mp2[y]-1+mp3[x+y]-1+mp4[x-y]-1;
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