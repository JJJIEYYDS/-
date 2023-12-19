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

struct node
{
    int x,y;
    bool operator<(const node b) const
    {
        if(b.x==x) return y>b.y;
        return x>b.x;
    }

};



void solve()
{
    cin>>n;

    priority_queue<node> p;
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        p.push({l,r});
    }
    ll res=0;

    while(p.size())
    {
        auto t = p.top();
        p.pop();

        if(!mp[t.x])
        {
            mp[t.x]=true;
            res++;
            continue;
        }

        if(!mp[t.y]) 
        {   
            t.x++;
            p.push({t.x,t.y});
        }
    }
    
   

    cout<<res<<endl;
    

    
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