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

int n,m,k,cnt;

char s[100][100];
bool row[10][10];
bool col[10][10];
bool small[10][10];
int a[10][10];
bool flag;

int judge(int x,int y)
{
    return 3*((x-1)/3)+(y-1)/3+1;
}

void dfs(int x,int y)
{

    if(x==10)
    {
        cout<<100000<<endl;
        flag=true;
        return ;
    }
    
    if(a[x][y])
    {
        if(y==9)
        {
            dfs(x+1,1);
        }
        else 
        {
            dfs(x,y+1);
        }
        if(flag) return ;
    }
    else
    {
        for(int i=1;i<=9;i++)
        {
            int k=judge(x,y);
            if(!row[x][i]&&!col[y][i]&&!small[k][i])
            {
                a[x][y]=i;
                row[x][i]=true;
                col[y][i]=true;
                small[k][i]=true;
                if(y==9)
                {
                    dfs(x+1,1);
                }
                else dfs(x,y+1);
                if(flag)
                {
                    return ;
                }
                else 
                {
                    a[x][y]=0;
                    row[x][i]=0;
                    col[y][i]=0;
                    small[k][i]=0;
                }
            }

        }
    }

    

}
void solve()
{
    flag=0;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cin>>s[i][j];
            a[i][j]=s[i][j]-'0';
            int k=judge(i,j);

            if(a[i][j])
            {
                row[i][a[i][j]]=1;
                col[j][a[i][j]]=1;
                small[k][a[i][j]]=1;
            }
        }
    }

    dfs(1,1);

    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
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
