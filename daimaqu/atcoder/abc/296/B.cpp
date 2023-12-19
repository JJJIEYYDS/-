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
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;
char s[10][10];

void solve()
{
    map<int,char> mp;
    for(int i=1;i<=8;i++) mp[i]='a'+i-1;

    for(int i=1;i<=8;i++)
    {
        cin>>s[i]+1;
    }

    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(s[i][j]=='*')
            {
                cout<<mp[j]<<8-i+1<<endl;
            }
        }
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