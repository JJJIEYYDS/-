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
const int N=2e5+10,INF=0x3f3f3f3f;

int n,m,k;
int a[N];

void solve()
{
    cin>>n>>k;
    int cnt1=0;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[1]) cnt1++;
        if(cnt1==k&&!res)
        {
            res=i;
        }
    }
    if(cnt1<k) 
    {
        cout<<"NO"<<endl;
        return ;
    }
    if(a[n]==a[1])
    {
        cout<<"YES"<<endl;
        return ;
    }

    int cnt2=0;
    for(int i=n;i>res;i--)
    {
        if(a[i]==a[n]) cnt2++;
    }

    if(cnt2>=k)
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

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