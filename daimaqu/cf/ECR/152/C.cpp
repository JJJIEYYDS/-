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

int n,m,k;
string s;
int pre[N],sux[N];

void solve()
{
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    memset(pre,0,sizeof pre);
    memset(sux,0,sizeof sux);
    set<pair<ll,ll>> st;
    
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1')
        {
            pre[i]=pre[i-1];
        }
        else
        {
            pre[i]=i;
        }
    }
    sux[n+1]=n+1;
    for(int i=n;i>=1;i--)
    {
        if(s[i]=='1') 
        {
            sux[i]=i;
        }
        else 
        {
            sux[i]=sux[i+1];
        }
    }

    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(pre[y]<sux[x])
        {
             st.insert({-1,-1});
             continue;
        }
        
        st.insert({sux[x],pre[y]});
    }

    cout<<st.size()<<endl;
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