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
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;

void solve()
{
    cin>>n>>k;
    int i=0;
    while(pow(k,i)<=n)
    {
        i++;
    }

    i-=1;

    ll sum=i*k;

    for(int j=1;j<=k-1;j++)
    {
        if(j*pow(k,i)<=n) sum++;
        else break;
    }

    cout<<sum<<endl;
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