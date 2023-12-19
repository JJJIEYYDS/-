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

void solve()
{
    int a,b;
    cin>>a>>b;

    bool flag1=0,flag2=0;
    for(int i=1;i<=9;i++)
    {
        if((i-1)%3==0) flag1=0,flag2=0;
        if(i==a) flag1=true;
        if(i==b) flag2=true;
        if(flag1&&flag2)
        {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
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