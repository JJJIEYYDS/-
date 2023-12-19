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

int sum[1000];

int depth;

bool dfs(int now,int d)
{
    if(d>depth) return false;
    if(n==now) return true;
    if(now<<(depth-d)<n) return false;

    sum[d]=now;

    for(int i=0;i<=d;i++)
    {
        if(dfs(sum[i]+now,d+1))
        {
                return true;
        }
        else if(dfs(now-sum[i],d+1))
        {
            return true;
        }

    }
    return false;
}
void solve()
{
   
    while(cin>>n&&n)
    {
        
        if(n==0||n==1)
        {
            cout<<0<<endl;
            continue;
        }

        for(depth=0;depth<15;depth++)
        {
            memset(sum,0,sizeof sum);
            if(dfs(1,0)) break;;
        }

        cout<<depth<<endl;

    }

}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;

    while(t--)
      solve();

    system("pause");
    return 0;
}