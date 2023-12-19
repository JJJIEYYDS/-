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
const int N=1e7+100,INF=0x3f3f3f3f;

ll n,m,k;

void solve()
{
    cin>>n>>m;
    bool flag =0;

    for(int i=2;i<=N;i++)
    {
        if(m%i==0)
        {
            flag = true;
        }
    }
    __int128 t1=n,t2=m;
    if(n>=m)
    {
        cout<<m<<endl;
        return ;
    }
    if(t2>t1*t1)
    {
        cout<<-1<<endl;
        return ;
    }

    while(1)
    {
        for(int i=sqrt(m);i>=1;i--)
        {
            if(i>n) continue;
            if(m/i>n) break;
            if(m%i==0)
            {
                if(i<=n&&m/i<=n)
                {
                    cout<<m<<endl;
                    return ;
                }
            }
        }
        m++;
    }

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