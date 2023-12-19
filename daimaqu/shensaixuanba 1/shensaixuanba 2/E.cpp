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

void solve()
{
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(x1==x2&&(y1==y3||y2==y3))
    {
        cout<<"NO"<<endl;
    }
    else if(x2==x3&&(y2==y1||y3==y1))
    {
        cout<<"NO"<<endl;
    }
    else if(x1==x3&&(y1==y2||y2==y3)) cout<<"NO"<<endl;
    else if(y1==y2&&(x1==x3||x2==x3)) cout<<"NO"<<endl;
    else if(y2==y3&&(x1==x2||x1==x3)) cout<<"NO"<<endl;
    else if(y1==y3&&(x1==x2||x3==x2)) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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