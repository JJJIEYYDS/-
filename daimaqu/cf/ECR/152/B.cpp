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
const int N=3e5+10,INF=0x3f3f3f3f;

int n,m,k;
struct node
{
    ll a,b;
    operator<(const node &p)const
    {
        if(a==p.a) return b>p.b;
        return a<p.a;
    }
};
void solve()
{
    cin>>n>>m;
    priority_queue<node> q;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>m)
        {
            if(x%m==0)
            {
                x=m;
            }
            else 
            {
                x%=m;
            }
        }
        q.push({x,i});
    }

    while(q.size())
    {
        auto t = q.top();
        q.pop();

        if(t.a-m<=0)
        {
            cout<<t.b<<' ';
        }
        else 
        {
            q.push({t.a-m,t.b});
        }
    }
    cout<<endl;
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