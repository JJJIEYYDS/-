#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m;

void solve()
{
    cin>>n>>m;

    for(int i=1;i<n;i+=2)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<i*m+j<<' ';
        }
        cout<<endl;
    }

    for(int i=0;i<n;i+=2)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<i*m+j<<' ';
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