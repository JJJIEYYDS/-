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
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;

void solve()
{
    cin>>n>>m;

    vector<ll> f(n+1);
    vector<vector<PLL>> v(n+1);
    vector<bool> st(n+1);

    for(int i=1;i<=m;i++)
    {
        int x,y,d;
        cin>>x>>y>>d;
        v[x].push_back({y,-d});
        v[y].push_back({x,d});
    }

    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            queue<ll> p;
            p.push(i);

            while(p.size())
            {
                ll t = p.front();
                p.pop();
                for(auto x:v[t])
                {
                    if(!st[x.first])
                    {
                        st[x.first]=true;
                        p.push(x.first);
                        f[x.first] = f[t] + x.second; 
                    }
                    else 
                    {
                        if(f[x.first]!=f[t]+x.second)
                        {
                            cout<<"NO"<<endl;
                            return ;
                        }
                    }
                }
            }
        }
    }
    cout<<"YES"<<endl;

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