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
const int N=40,INF=0x3f3f3f3f,mod=998244353;

ll n,m,k,q;
string s,s1;
string str;
bool st[N];

void dfs(int u)
{
    if(st[u]) return ;
    for(int i=0;i<s.size();i++)
    {
        
    }
}
void solve()
{
    while(cin>>s>>s1)
    {
        memset(st,0,sizeof st);
        dfs(0);
    }

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