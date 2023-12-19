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
const int N=1e3+10,INF=0x3f3f3f3f;

int n,m,k;


int p[N],cnt;
bool st[N];

int dp[N];

void init()
{
    for(int i=2;i<=N;i++)
    {
        if(!st[i]) p[cnt++] = i;
        for(int j=0;i*p[j]<=N;j++)
        {
            st[i*p[j]] = true;
            if(i%p[j]==0) break;
        } 
    }
}


void solve()
{
    
    cin >> n;
    init();
    st[1]=true;

    dp[0] = 1;
    
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            for(int j=i;j<=n;j++)
            {
                dp[j]+=dp[j-i];
            }
        }
    }

    cout<<dp[n]<<endl;

    

    


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