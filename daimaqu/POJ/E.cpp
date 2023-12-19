#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<set>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m;
int ans=INF;

int h[N],e[2*N],ne[2*N],idx;
bool st[N];
set<int> s;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;

}

int dfs(int u)
{
    st[u]=true;
    //cout<<u<<endl;
    int res=0,num=1;

    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            int s=dfs(j);
            res=max(res,s);
            num+=s;
        }
    }
    res=max(res,n-num);
	if(ans>res)
    {
    	ans=min(ans,res);
        s.clear();
        s.insert(u);
    }
    else if(ans==res)
    {
        s.insert(u);
    }


    return num;

}

void solve()
{
    cin>>n;
    memset(h,-1,sizeof h);

    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
       

    }
    //cout<<1<<endl;
    dfs(1);

    for(set<int>::iterator it=s.begin();it!=s.end();it++)
		cout<<*it<<" ";



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