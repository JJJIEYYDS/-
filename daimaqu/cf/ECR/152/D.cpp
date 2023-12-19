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
const int N=6e5+10,INF=0x3f3f3f3f;

int n,m,k;
int a[N],st[N];


void solve()
{
    cin>>n;
    vector<int> v;
    map<PII,int> mp;
    
    
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
      if(a[i]==0)
      {
        v.push_back(i);
      }
    }

    if(n==1) 
    {
      cout<<1<<endl;
      return ;
    }


    if(v.size()==0)
    {
      cout<<1<<endl;
      return ;
    }
    if(v.size()==1) 
    {
      if(v[0]==1||v[v.size()-1] == n)
      {
        cout<<1<<endl;
      }
      else 
      {
        cout<<2<<endl;
      }
      return ;
    }
    
    ll ans=0;

    for(int i=0;i<v.size()-1;i++)
    {
      for(int j=v[i]+1;j<=v[i+1]-1;j++)
      {
        if(a[j]==2)
        {
          mp[{v[i+1],v[i]}]=1;
          break;
        }
      }
    }

    if(v[0]!=1)
    {
      ans++,st[v[0]]=true;
    }

    for(int i=0;i<v.size()-1;i++)
    {
      if(v[i+1]-v[i]==1) continue;
      else
      {
        ans++;
        if(mp.find({v[i+1],v[i]})!=mp.end())
        {
          st[v[i+1]]  = true,st[v[i]]=true;
        }
        else
        {
          if(!st[v[i]])
          {
            st[v[i]] = true;
          }
          else
          {
            st[v[i+1]]=true;
          }
        }
      }
    }

    if(v[v.size()-1]!=n)
    {
      ans++;
        if(!st[v[v.size()-1]])
          {
            st[v[v.size()-1]] = true;
          }
    }
    
    for(int i=1;i<=n;i++)
    {
      if(a[i]==0&&!st[i]) ans++; 
    }

    cout<<ans<<endl;
    

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
