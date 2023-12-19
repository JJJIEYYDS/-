#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;

void solve()
{
    cin>>n;

    if(n==1) cout<<1<<endl;
    else if(n==2) cout<<2<<' '<<1<<endl;
    else
    {
       if(n%2==0)
       {
        cout<<2<<' ';
        for(int i=5;i<=n-1;i+=2) cout<<i<<' ';
        cout<<1<<' ';
        for(int i=n;i>=4;i-=2) cout<<i<<' ';
        cout<<3<<' ';
        cout<<endl;
       }
       else
       {
        cout<<2<<' ';
        for(int i=5;i<=n;i+=2) cout<<i<<' ';
        cout<<1<<' ';
        for(int i=n-1;i>=4;i-=2) cout<<i<<' ';
        cout<<3<<' ';
        cout<<endl;
       }
    }

    
   
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