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
int a[N],b[N];
int calc(int a,int b)
{
    if(a==0&&b==0) return 0;

    int d=__gcd(a,b);

    a/=d,b/=d;

    if(a%2==0) return 1;
    if(b%2==0) return 2;
    return 3;
}

void solve()
{
    cin>>n;
    bool cnt1 = 0,cnt2 = 0;

    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    } 
    bool flag1=0,flag2=0,flag3=0;

    for(int i=1;i<=n;i++)
    {
        if(calc(a[i],b[i])==1) flag1=true;
        else if(calc(a[i],b[i])==2) flag2=true;
        else if(calc(a[i],b[i])==3) flag3 = true;
    }
    if(flag1+flag2+flag3<=1)
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

    while(t--)
      solve();

    system("pause");
    return 0;
}