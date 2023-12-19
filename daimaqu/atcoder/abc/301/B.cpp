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


int n,m,k;

int a[1000];

void solve()
{
    cin >> n;

    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<' ';
        if(a[i]>a[i+1]&&i!=n)
        {
            for(int j=a[i]-1;j>a[i+1];j--)
            {
                cout<<j<<' ';
            }
        }
        else if(a[i]<a[i+1]&&i!=n)
        {
            for(int j=a[i]+1;j<a[i+1];j++)
            {
                cout<<j<<" ";
            }
        }
    }

    cout<<endl;


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