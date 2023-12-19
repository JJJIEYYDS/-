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
    cin>>n;
    string s;
    cin>>s;
    int sum=1,res=0;
    res=max(res,sum);
    for(int i=0;i<n;i++)
    {
        if(s[i]==s[i+1])
        {
            sum++;
            res=max(res,sum);
        }
        else 
        {
            sum=1;
            res=max(res,sum);
        }
    }

    cout<<res+1<<endl;

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