#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e6+10,INF=0x3f3f3f3f;

int n,m,k;

bool st[N];

void solve()
{
    cin>>n;
    
    if(st[n])
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;


}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;

    for(int i=2;i<=10000;i++)
    {
        int res=1+i+i*i,cnt=i*i*i;
        while(res<=N)
        {
            st[res]=true;  
            res+=cnt;
            cnt*=i;
        }
    }
    while(t--)
      solve();

    system("pause");
    return 0;
}