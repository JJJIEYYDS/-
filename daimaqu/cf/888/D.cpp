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
const int N=2e5+10,INF=0x3f3f3f3f;

ll n,m,k;
ll s[N],a[N];

void solve()
{
    cin>>n;
    set<ll> st;
    memset(a,0,sizeof a);
    memset(s,0,sizeof s);
    

    for(int i=1;i<=n-1;i++)
    {
        cin>>s[i];
    }

    bool flag1 = false,flag2=false;
    ll t=0,t1=0;

    for(int i=1;i<n;i++)
    {
        a[i]=s[i]-s[i-1];
        if(st.find(a[i])!=st.end())
        {
            if(flag2)
            {
                cout<<"NO"<<endl;
                return ;
            }
            flag2=true;
            t1=a[i];
        }
        if(flag1)
        {
            if(a[i]>n) 
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        if(a[i]>n&&!flag1)
        {
            flag1=true;
            t=a[i];
        }
        
        st.insert(a[i]);

    }
    if(!flag1&&!flag2)
    {
       cout<<"YES"<<endl;
    }
    else 
    {
        if(t1&&t)
        {
            cout<<"NO"<<endl;
            return;
        }
        if(t)
        {
            for(int i=1;i<=n;i++)
            {
                if(st.find(i)==st.end()&&st.find(t-i)==st.end()&&t-i<=n&&t-i!=i&&t-i>=1)
                {
                    cout<<"YES"<<endl;
                    return;
                }
            }
        cout<<"NO"<<endl;
        }
        else if(t1)
        {
             for(int i=1;i<=n;i++)
             {
                if(st.find(i)==st.end()&&st.find(t1-i)==st.end()&&t-i<=n&&t1-i!=i&&t1-i>=1)
                {
                    cout<<"YES"<<endl;
                    return;
                }
             }
        cout<<"NO"<<endl;
        }
    }
    
    st.clear();
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