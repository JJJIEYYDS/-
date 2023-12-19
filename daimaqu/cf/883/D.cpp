#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=2e5+10,INF=0x3f3f3f3f;

double n,m,k,h,d;

double a[N];

void solve()
{
    cin>>n>>d>>h;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    double res=0;
    for(int i=1;i<=n-1;i++)
    {
        if(a[i+1]-a[i]>=h)
        {
            res+=d*h*0.5;
        }
        else 
        {
            double t=h-(a[i+1]-a[i]);
            double s=t/h*d*t*0.5;
            res+=d*h*0.5;
            res-=s;
        }
    }
    res+=d*h*0.5;
    cout<<fixed<<setprecision(7)<<res<<endl;
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