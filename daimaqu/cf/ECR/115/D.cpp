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
const int N=2e5+10,INF=0x3f3f3f3f,mod=998244353;

ll n,m,k,q;
int inv[N],pac[N],invpac[N];

__int128 c(ll a,ll b)
{
    __int128 res1=1,res2=1,res3=1;
    for(int i=a-3+1;i<=a;i++)
    {
        res1*=i;
    }
    return res1/(ll)6;
}

void solve()
{
    cin>>n;
    vector<PII> a(n+1);
    map<int,int> mp2;
    vector<vector<int>> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
        mp2[a[i].second]++;
        v[a[i].first].push_back(i);
    }

    ll x=c(n,3);

    for(int i=1;i<=n;i++)
    {
        if(v[i].size()>=2)
        {
            for(int j=0;j<v[i].size();j++)
            {
                if(mp2[a[v[i][j]].second]>=2)
                {
                    x-=(v[i].size()-1)*(mp2[a[v[i][j]].second]-1);
                }
            }
        }
    }
    cout<<x<<endl;


    
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