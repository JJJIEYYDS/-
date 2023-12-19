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
    int x=100;//特判1 2
    for(int i=1;i<n;i++)
    {
        if(n%i!=0)
        {
            x=i;
            break;
        }
        
    }

    for(int i=0;i<n;i++)
    {
        char c='a'+i%x;
        cout<<c;
    }
    cout<<endl;

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