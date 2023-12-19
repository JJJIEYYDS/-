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
int t[N];

void init()
{
    t[1] = 1, t[2] = 0;

    for(int i=3;i<=N;i++)
    {
        t[i] = t[i-1] + t[i-2]; 
    }
}

void solve()
{
    cin>>n>>k;

    int ans=0;
    
    if(k>50) 
    {
        cout<<0<<endl;
        return ;
    }
    for(int i=0;i<=n;i++)
    {
        int x = t[k] * i;
        if(x>n) break;

        if((n-x)%t[k+1]!=0) continue;

        int y = (n-x)/t[k+1];
        if(y<i) continue;
        ans++;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    init();
    while(t--)
      solve();

    system("pause");
    return 0;
}