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
const int N=3e5+10,INF=0x3f3f3f3f;

int n,m,k;
int a[N];
int x;
void solve()
{
    cin>>n>>x;
    map<int,int> mp;

    for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]++;

    for(int i=1;i<=n;i++)
    {
        if(mp.find(a[i]-x)!=mp.end())
        {
            cout<<"Yes"<<endl;
            return ;
        }
    }

    cout<<"No"<<endl;




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