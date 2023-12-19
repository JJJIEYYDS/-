#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

long long n,m,k;

bool cmp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll>b)
{   
    if(a.first.first==b.first.first)
    {
        if(a.first.second==b.first.second) return a.second<b.second;
        return a.first.second<b.first.second;
    }
    return a.first.first>b.first.first;
}



void solve()
{
    cin>>n>>m>>k;

    priority_queue<ll,vector<ll>,greater<ll>> p;
    vector<pair<pair<ll,ll>,ll>> a;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            long long x;
            cin>>x;
            p.push(x);
        }
        long long res=0,ans=0,cnt=0;
        while(p.size())
        {
            long long t=p.top();
            p.pop();
            res+=t;
            if(res<=k)
            {
                cnt++;
                ans+=res;
            }
            else
            {
                continue;
            }
        }
        
        a.push_back({{cnt,ans},i});
    }
    sort(a.begin(),a.end(),cmp);

    for(int i=0;i<a.size();i++)
    {
        if(a[i].second==1) 
        {
            cout<<i+1<<endl;
            
            return ;
        }
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