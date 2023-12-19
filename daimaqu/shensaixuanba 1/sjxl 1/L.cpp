#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,q;

int a[N];
map<int,vector<int> > mp;
void solve()
{
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]].push_back(i);
    }

    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(mp[x].size()<y) cout<<-1<<endl;
        else cout<<mp[x][y-1]<<endl;
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