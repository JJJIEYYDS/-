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

char a[110][110];
void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]+1;
    }
    char temp1=a[1][n];

    for(int i=n;i>=2;i--)
    {
        a[1][i]=a[1][i-1];
    }

    char temp2=a[n][n];

    for(int i=n;i>=3;i--)
    {
        a[i][n]=a[i-1][n];
    }

    char temp3=a[n][1];

    for(int i=1;i<=n-2;i++)
    {
        a[n][i]=a[n][i+1];
    }

    for(int i=1;i<=n-2;i++)
    {
        a[i][1]=a[i+1][1];
    }

    a[2][n]=temp1;
    a[n][n-1]=temp2;
    a[n-1][1]=temp3;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
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
    //cin>>t;

    while(t--)
      solve();

    system("pause");
    return 0;
}