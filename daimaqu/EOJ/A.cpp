#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<iomanip>


using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

ll n,m;

double a[N];

void solve()
{
    cin>>n;

    ll sum=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];sum+=a[i];
    }

    sort(a+1,a+n+1,greater<double>());

    double res=0,ans=0;
    
    for(int i=1;i<=n;i++)
    {
        double j=i;
        ans+=a[i];
        res=max(res,(ans/sum-j/n)*100);
        //cout<<ans/sum<<' '<<j/n<<endl;
    }

    cout<<fixed<<setprecision(6)<<res<<endl;

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