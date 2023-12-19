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
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;
bool st[N];
int p[N],cnt;
int d[N];

string start;

string tostring(int n)
{
  string s;
  int t=1000;
  for(int i=0;i<4;i++)
  {
    s+=(n/t%10)+'0';
    t/=10;
  }
  return s;
}

int stoint(string s)
{
  int t=0;
  for(int i=0;i<4;i++)
  {
    t=t*10+(s[i]-'0');
  }

  return t;
}

void make_prime()
{
  for(int i=2;i<=1e4;i++)
  {
    if(!st[i]) p[cnt++]=i;
    for(int j=0;p[j]*i<=1e4;j++)
    {
      st[p[j]*i]=true;
      if(i%p[j]==0) break;
    }
  }
}

void bfs()
{
  queue<pair<string,int> > p;
    
  memset(d,0,sizeof d);
    
  p.push({start,0});

  while(p.size())
  {
    pair<string,int> t=p.front();
    p.pop();
    

	  string  s=t.first;
    int y=t.second;

    int temp=stoint(s);

    d[temp]=1;

    if(temp==m)
    {
      cout<<y<<endl;
      return ;
    }

    for(int i=0;i<4;i++)
    {
      for(int j=0;j<=9;j++)
      {
        if(i==0&&j==0) continue;

        char c=s[i];
        
        if(c==j+'0') continue;

        s[i]=j+'0';
          
        int k=stoint(s);
          
        if(!d[k]&&!st[k]&&k>999&&k<=10000)
        {
          d[k]=1;
          p.push({s,y+1});
        }

        s[i]=c;//关键

      }
    }

  }

}

void solve()
{
    cin>>n>>m;
    
	  start=tostring(n);
     
    make_prime();
    
    bfs();
    
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