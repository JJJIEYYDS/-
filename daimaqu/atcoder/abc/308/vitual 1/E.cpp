#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;

typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;
typedef long long ll;
const int N=2e5+10,INF=0x3f3f3f3f;

int n,m,k;
int a[N];
char s[N];

ll f(int i,int j,int k)
{
  bool st[4]={0};
  st[i]=true;
  st[j]=true;
  st[k]=true;
  for(int i=0;i<4;i++)
  {
    if(!st[i])
    {
       return i;
    }
  }
}


void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }
    map<ll,ll> m,X; 

    cin>>s+1;

    ll res=0;

    for(int i=1;i<=n;i++)
    {
      if(s[i]=='X')
      {
        X[a[i]]++;
      }
    }

    for(int i=1;i<=n;i++)
    {
      if(s[i]=='M') m[a[i]]++;
      else if(s[i]=='E')
      {
        for(auto x:m)
        {
          for(auto y:X)
          {
            res+=f(a[i],x.first,y.first)*(x.second*y.second);
          }
        }
      }
      else X[a[i]]--;
    }

    cout<<res<<endl;

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