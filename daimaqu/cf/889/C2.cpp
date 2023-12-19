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
const int N=1e5+10,INF=0x3f3f3f3f,mod=998244353;

int n,m,k;

void solve()
{
    cin>>n;
    vector<int> a(n+1);
    vector<PII> v;
    int mi=1e9,t1=-1,mx=0,t2=-1;
    int cnt1=0,cnt2=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
        {
            cnt1++;
            if(a[i]<mi)
            {
                mi=a[i];
                t1=i;
            }
        }
        if(a[i]>0)
        {
            cnt2++;
            if(a[i]>mx)
            {
                mx=a[i];
                t2=i;
            }
        }
    }

    if(t1==-1&&t2==-1)
    {
        cout<<0<<endl;
        return ;
    }
    if(t1==-1)
    {
        for(int i=1;i<n;i++)
        {
            v.emplace_back(i+1,i);
        }  
    }
    else if(t2==-1)
    {
        for(int i=n;i>=2;i--)
        {
            v.emplace_back(i-1,i);
        }
    }
    else
    {
        if(abs(mi)>=abs(mx))
        {
            if(cnt2<=12)
            {
                for(int i=1;i<=n;i++)
                {
                    if(a[i]>0)
                    {
                        v.emplace_back(i,t1);
                    }
                }
                for(int i=n;i>=2;i--)
                {
                    v.emplace_back(i-1,i);
                }
            }
            else
            {
                for(int i=1;i<=5;i++)
                {
                    v.emplace_back(t2,t2);
                }
                for(int i=1;i<=n;i++)
                {
                    if(a[i]<0)
                    {
                        v.emplace_back(i,t2);
                    }
                }

                for(int i=1;i<n;i++)
                {
                    v.emplace_back(i+1,i);
                }
            }
        }
        else
        {
            if(cnt1<=12)
            {
                for(int i=1;i<=n;i++)
                {
                    if(a[i]<0)
                    {
                        v.emplace_back(i,t2);
                    }
                }
                for(int i=1;i<n;i++)
                {
                    v.emplace_back(i+1,i);
                }
            }
            else
            {
                for(int i=1;i<=5;i++)
                {
                    v.emplace_back(t1,t1);
                }
                for(int i=1;i<=n;i++)
                {
                    if(a[i]>0)
                    {
                        v.emplace_back(i,t1);
                    }
                }
                 for(int i=n;i>=2;i--)
                {
                    v.emplace_back(i-1,i);
                }
            }
        }
    }
    cout<<v.size()<<endl;
    for(auto [x,y]:v)
    {
        cout<<x<<' '<<y<<endl;
    }
    v.clear();



    
    
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