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
    cin>>n>>k;

    if(n%k==0) 
    {
        cout<<2<<endl;
        cout<<n-1<<' '<<1<<endl;
    }
    else 
    {
        cout<<1<<endl;
        cout<<n<<endl;
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