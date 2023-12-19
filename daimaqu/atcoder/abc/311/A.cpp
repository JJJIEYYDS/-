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

string s;

void solve()
{
    cin>>n>>s;
    s=' '+s;
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='A') cnt1++;
        if(s[i]=='B') cnt2++;
        if(s[i]=='C') cnt3++;
        if(cnt1&&cnt2&&cnt3) 
        {
            cout<<i<<endl;
            return ;
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