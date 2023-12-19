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
const int N=1e6+10,INF=0x3f3f3f3f;

int n,m,k;
int a,b,c;

struct node
{
  int a,b;
  int father,set;
}ot[N],t;

bool st[110][110];

void bfs()
{
    int r=0,l=1;

    while(r<l)
    {
      for(int i=1;i<=6;i++)
      {
         t=ot[r];
         t.set=i;
         t.father=r;
         switch(t.set)
         {
            case 1:
              t.a=a;
              break;

            case 2:
              t.b=b;
              break;

            case 3:
              t.a=0;
              break;

            case 4:
              t.b=0;
              break;

            case 5:
              if(t.a+t.b<=b)
              {
                t.b=t.b+t.a;
                t.a=0;
              }
              else 
              {
                t.a=t.a-(b-t.b);
                t.b=b;
              }
              break;

            case 6:
              if(t.a+t.b<=a)
              {
                t.a=t.a+t.b;
                t.b=0;
              }
              else 
              {
               
                t.b=t.b-(a-t.a);
                  t.a=a;
              }
              break;
         }
          
         if(st[t.a][t.b]) continue;
         st[t.a][t.b]=true;

         ot[l++]=t;

         if(t.a==c||t.b==c)
         {
            vector<int> ans;
            int g=l-1;
            while(1)
            {
              ans.push_back(ot[g].set);
              g=ot[g].father;
              if(g==-1)
              {
                break;
              }
            }
            cout<<ans.size()-1<<endl;

            for(int i=ans.size()-1;i>=0;i--)
            {
              switch(ans[i])
              {
                case 1: 
                cout<<"FILL(1)"<<endl;
                break;
                case 2:
                cout<<"FILL(2)"<<endl;
                break;
                case 3:
                cout<<"DROP(1)"<<endl;
                break;
                case 4:
                cout<<"DROP(2)"<<endl;
                break;
                case 5:
                cout<<"POUR(1,2)"<<endl;
                break;
                case 6:
                cout<<"POUR(2,1)"<<endl;
                break;
              
              }
              
            }
            return ;
         }


      }
      r++;
      
    }
    cout<<"impossible"<<endl;
    


}

void solve()
{
    cin>>a>>b>>c;
    ot[0].a=0,ot[0].b=0,ot[0].father=-1,ot[0].set=-1;
    st[0][0]=true;
    bfs();
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