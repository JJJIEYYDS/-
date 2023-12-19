#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=2e5+10,INF=0x3f3f3f3f;

int n,m,k;
int a[N];

void solve()
{
    cin>>n;
    long long res=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    res=a[1];

    for(int i=2;i<=n;i++)
    {
        res&=a[i];
    }
    long long ans=a[1],cnt=0;
    
    if(res==0)
    {
        for(int i=1;i<=n;i++)
        {
            
            if(ans==0) 
            {
                cnt++;
                ans=a[i+1];

            }
            ans&=a[i+1];
        }
        
        cout<<cnt<<endl;
    }
    else 
    {
        cout<<1<<endl;
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