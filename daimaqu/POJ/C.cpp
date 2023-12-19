#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
//#include <unordered_map>
#include <set>
//#include <unordered_set>
#include <queue>
#include <deque>
#define IOS ios::sync_with_stdio(false); \
        cin.tie(0);              \
        cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int N=1e7+10;
const int mod=1e9+7;

int n,q;
int a[N];

struct node
{
    int l,r;
    int lc,rc,mx;
}tr[N<<2];

void bt(int u,int l,int r)
{
    tr[u].l=l;
    tr[u].r=r;
    if(l==r)
    {
        tr[u].lc=tr[u].rc=tr[u].mx=1;
        return;    
    }
    int mid = (l + r)>>1;
    bt(u<<1,l,mid);
    bt(u<<1|1,mid+1,r);

    int count;
    if(a[tr[u<<1].r]==a[tr[u<<1|1].l])
    {
        count=tr[u<<1].rc+tr[u<<1|1].lc;
    }
    else count=0;

    tr[u].mx=max(max(tr[u<<1].mx,tr[u<<1|1].mx),count);
    tr[u].lc=tr[u<<1].lc;

    if(tr[u<<1].lc==mid-l+1&&a[tr[u<<1|1].l]==a[tr[u<<1].r])
    tr[u].lc=mid-l+1+tr[u<<1|1].lc;

    tr[u].rc=tr[u<<1|1].rc;

    if(tr[u<<1|1].rc==r-mid&&a[tr[u<<1|1].l]==a[tr[u<<1].r])
    tr[u].rc=r-mid+tr[u<<1].rc;
}

int query(int u,int l,int r)
{
    if(tr[u].l==l&&tr[u].r==r)
    return tr[u].mx;

    int mid = (tr[u].l + tr[u].r)>> 1;
    if(r<=mid)return query(u<<1,l,r);
    else if(l>mid)return query(u<<1|1,l,r);
    else 
    {
        int a1=query(u<<1,l,mid);
        int a2=query(u<<1|1,mid+1,r);
        int a3=0;

        if(a[tr[u<<1].r]==a[tr[u<<1|1].l])
    {
        a3=min(tr[u<<1].rc,mid-l+1)+min(tr[u<<1|1].lc,r-mid);
    }
    return max(max(a1,a2),a3);
    }
}

void solve()
{
while(scanf("%d",&n)!=0)
{
    if(n==0)break;
    scanf("%d",&q);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
           bt(1,1,n);
while(q--)
{
    int l,r;
    scanf("%d%d",&l,&r);
    printf("%d\n",query(1,l,r));
}
}
}
int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
