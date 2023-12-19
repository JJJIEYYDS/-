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
const int N=1e5+10,INF=0x3f3f3f3f,mod=998244353;

ll n,m,k,q;
string s;

void solve()
{
    cin>>s;
    bool flag=false;
    for(int i=0;i<(s.size()/2+1);i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            for(int j=i;j<s.size()-i-1;j+=2)
            {
                if(s[j]!=s[j+1]) flag=true;
            }
            break;
        }
        
    }
    if(flag) cout<<"Alice"<<endl;
    else cout<<"Draw"<<endl;


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