#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<set>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e3+10,INF=0x3f3f3f3f;

int n,m;

int g[N][N];

void solve()
{
    cin>>n>>m;

    set<int> s;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
            s.insert(g[i][j]);
        }
    }

    cout<<s.size()<<endl;
    
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