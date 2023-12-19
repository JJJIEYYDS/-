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
const int N=2e5+10,INF=0x3f3f3f3f;

int n,m,k,q;
int h[N],ans[N],p[N];

struct node
{
    int a,b,c;
    operator<(const node &p) const
    {
        return a<p.a;
    }

}w[N];

struct op
{
    int a,b,c,d;
    operator<(const op&p) const
    {
        return a<p.a;
    }
}qu[N];

ll find(ll x)
{
    if(x!=p[x])
    {
        p[x]=find(p[x]);
    }

    return p[x];
}



void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
        p[i]=i;
    }

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        w[i]={max(h[a],h[b]),a,b};
    }

    for(int i=1;i<=n;i++)
    {
        cout<<w[i].a<<endl;
    }

    sort(w+1,w+m+1);

    cin>>q;

    for(int i=1;i<=q;i++)
    {
        int a,b,e;
        cin>>a>>b>>e;
        
        ans[i]=0;
        qu[i]={h[a]+e,a,b,i};
    }   
    sort(qu+1,qu+q+1);


    for(int i=1,j=1;i<=q;i++)
    {
        while(j<=m&&qu[i].a>=w[j].a)
        {
            ll pb=find(w[j].b),pc=find(w[j].c);
            j++;
            if(pb==pc) continue;
            p[pb] = pc;
        }
        if(find(qu[i].b)==find(qu[i].c)) ans[qu[i].d]=1;
    }

    for(int i=1;i<=q;i++) cout<<(ans[i]?"YES":"NO")<<endl;
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