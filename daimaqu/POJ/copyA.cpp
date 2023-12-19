#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e7+10,INF=0x3f3f3f3f;

int n,m,cou;
int h[N];
bool st[100005];

struct node
{
    int l,r;
    int cover;
}tr[400005];

void build(int u,int l,int r)
{
    if(l==r)
    {
        tr[u].r=tr[u].l=l;
        tr[u].cover=0;
        return ;
    }

    tr[u].r=r;
    tr[u].l=l;
    tr[u].cover=0;

    int mid=(l+r)>>1;

    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

}

void push_down(int u)
{
    if(tr[u].cover==0)
    {
        return ;
    }

    tr[u<<1].cover=tr[u].cover;
    tr[u<<1|1].cover=tr[u].cover;
    tr[u].cover=0;

}
void modify(int u,int l,int r,int x)
{
    if(tr[u].l>=l&&tr[u].r<=r)
    {
        tr[u].cover=x;
        return ;
    }
    push_down(u);

    int mid=(tr[u].r+tr[u].l)>>1;

    if(l<=mid)
    {
        modify(u<<1,l,r,x);
    }
    if(r>mid)
    {
        modify(u<<1|1,l,r,x);
    }

}

void query(int u)
{
    if(tr[u].cover&&!st[tr[u].cover])
    {
        cou++;
        st[tr[u].cover]=true;
        return ;
    }
    
    if(tr[u].r==tr[u].l)
    return;

    push_down(u);

    query(u<<1);
    query(u<<1|1);

}
void solve()
{
    cin>>n;
    memset(st,0,sizeof st);
    cou=0;
    vector<pair<ll,ll> > v;
    vector<ll> a;

    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;

        v.push_back({x,y});
        a.push_back(x);
        a.push_back(y);
        
    }

    sort(a.begin(),a.end());//排序
    
    a.erase(unique(a.begin(),a.end()),a.end());//去重

    for(int i=0;i<a.size();i++)
    {
        h[a[i]] = i+1;
    }
    
    build(1,1,a.size());

    for(int i=0;i<n;i++)
    {
        int l=h[v[i].first];
        int r=h[v[i].second];

        modify(1,l,r,i+1);
    }

    query(1);

    cout<<cou<<endl;


    





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