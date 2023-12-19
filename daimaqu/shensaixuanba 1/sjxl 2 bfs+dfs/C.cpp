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
const int N=3e5+10,INF=0x3f3f3f3f;

int n,m,k;

int d[N];

void bfs()
{
    for(int i=0;i<=1e5;i++)
    {
        d[i]=-1;
    }

    int dx[3]={1,-1,n};

    queue<int> p;

    p.push(n);
    d[n]=0;
    while(p.size())
    {
        int t=p.front();
        
        p.pop();
        if(t==m)
        {
            return;
        }
        dx[2]=t;

        for(int i=0;i<3;i++)
        {
            int x=t+dx[i];
            
            if(d[x]==-1&&x<=100000&&x>=0)
            {
                d[x]=d[t]+1;
                p.push(x);
            }
        }

    }
}


void solve()
{
    cin>>n>>m;
    
    if(n>=m)//特判只能减
    {
        cout<<n-m<<endl;
        return;
    }
  	bfs();
   
    cout<<d[m]<<endl;
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