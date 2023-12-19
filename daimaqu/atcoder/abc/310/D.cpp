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

int n,m,k,t;

vector<int> a,b;

int team[100];

ll res;

void dfs(int u, int d)
{
    if(u>n)
    {
        if(d!=t+1) return ;
        for(int i=0;i<m;i++)
        {
            if(team[a[i]]==team[b[i]])
            return;
        }
        res++;
        return ;

    }

    for(int i=1;i<=d;i++)
    {
        team[u]=i,dfs(u+1,max(i+1,d));
    }
}

void solve()
{
    cin >> n >> t >> m;


    for(int i = 1; i <= m; i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }

    dfs(1,1);

    cout<<res<<endl;



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