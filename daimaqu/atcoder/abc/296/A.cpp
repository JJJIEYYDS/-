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
    bool flag =false;

    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1]) 
        flag=true;
    }

    if(flag) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
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