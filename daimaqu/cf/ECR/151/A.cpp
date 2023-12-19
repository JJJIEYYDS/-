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

int n,m,k,t;

void solve()
{
    cin>>n>>k>>t;
    if(k==1)
    {
        cout<<"NO"<<endl;
        return ;
    }

    if(t!=1)  
    {
        cout<<"YES"<<endl;
        cout<<n<<endl;
        for(int i=1;i<=n;i++) cout<<1<<' ';
        cout<<endl;
    }
    else 
    {
        if(n%2==0)
        {
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
            for(int i=1;i<=n/2;i++)
            {
                cout<<2<<' ';
            }
            cout<<endl;
        }
        else
        {
            if(k==2)
            {
                cout<<"NO"<<endl;
            }
            else 
            {
                if(n%3==0)
                {
                    cout<<"YES"<<endl;
                    cout<<n/3<<endl;
                    for(int i=1;i<=n/3;i++)
                    {
                        cout<<3<<' ';
                    }
                    cout<<endl;
                }
                else
                {
                    for(int i=1;i<=n;i++)
                    {
                        for(int j=1;j<=n;j++)
                        {
                            if(i*2+j*3==n)
                            {
                                cout<<"YES"<<endl;
                                cout<<i+j<<endl;
                                for(int k=1;k<=i;k++)
                                {
                                    cout<<2<<' ';
                                }
                                for(int k=1;k<=j;k++)
                                {
                                    cout<<3<<' ';
                                }
                                cout<<endl;
                                return ;
                            }
                        }
                    }
                }

            }
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