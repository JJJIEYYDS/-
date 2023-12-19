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

int a[10];

void solve()
{
    bool flag=0;
    for(int i=1;i<=8;i++)
    {
        cin>>a[i];
        if(a[i]%25==0&&a[i]>=100&&a[i]<=675&&a[i]>=a[i-1])
        {
            continue;
        }
        else flag=true;
        
    }
    if(flag) 
    {
        cout<<"No"<<endl;
    }
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