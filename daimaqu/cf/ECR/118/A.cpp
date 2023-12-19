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
    ll x1,p1,x2,p2;
    cin>>x1>>p1>>x2>>p2;

    vector<int> a,b;
    int cnt1=0,cnt2=0;
    while(x1)
    {
        cnt1++;
        a.emplace_back(x1%10);
        x1/=10;
    }
    while(x2)
    {
        cnt2++;
        b.emplace_back(x2%10);
        x2/=10;
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    

    if((cnt1+p1)!=(cnt2+p2))
    {
        
        if(cnt1+p1>cnt2+p2) cout<<">"<<endl;
        else cout<<"<"<<endl;
    }
    else
    {
        int x=a.size(),y=b.size();
        if(x>y)
        {
            for(int i=0;i<y;i++)
            {
                if(a[i]<b[i])
                {
                    cout<<"<"<<endl;
                    return ;
                }
                else if(a[i]>b[i])
                {
                    cout<<">"<<endl;
                    return ;
                }
            }
            for(int i=y;i<x;i++)
            {
                if(a[i]!=0) 
                {
                    cout<<">"<<endl;
                    return ;
                }
            }
            cout<<"="<<endl;
        }
        else if(x<y)
        {
            for(int i=0;i<x;i++)
            {
                if(a[i]<b[i])
                {
                    cout<<"<"<<endl;
                    return ;
                }
                else if(a[i]>b[i])
                {
                    cout<<">"<<endl;
                    return ;
                }
            }
            for(int i=x;i<y;i++)
            {
                if(b[i]!=0) 
                {
                    cout<<"<"<<endl;
                    return ;
                }
            }
            cout<<"="<<endl;
        }
        else
        {
            for(int i=0;i<x;i++)
            {
                if(a[i]>b[i]) 
                {
                    cout<<">"<<endl;
                    return ;
                }
                else if(a[i]<b[i]) 
                {
                    cout<<"<"<<endl;
                    return ;
                }
            }
            cout<<"="<<endl;
        }
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