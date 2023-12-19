#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=2e5+10,INF=0x3f3f3f3f;

int n;

void solve()
{
    cin>>n;

    vector<vector<int>> v(n+1);

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;

        v[x].push_back(y);
    }

    ll res=0;
    
    for(int i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end(),greater<int>());
        for(int j=0;j<min(i,(int)v[i].size());j++)
        {
            res+=v[i][j];
        }
       
    }

    cout<<res<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;

    while(t--)
      solve();

    system("pause");
    return 0;
}