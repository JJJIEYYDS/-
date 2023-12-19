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

ll n,m,k,q;

int a[1110][10];
void solve()
{
    cin>>n;
    vector<vector<int>> v(6);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==1)
            {
                v[j].push_back(i);
            }
        }
    }

    int x=n/2;

    bool flag =false;

    for(int i=1;i<=5;i++)
    {
        for(int j=i+1;j<=5;j++)
        {
            if(v[i].size()>=x&&v[j].size()>=x)
            {
                set<int> st;
                for(auto xx:v[i]) st.insert(xx);
                for(auto xx:v[j]) st.insert(xx);
                int g=v[i].size()+v[j].size()-st.size();
                int t=max(v[i].size(),v[j].size());
                if((v[i].size()-g)>=x||(v[j].size()-g)>=x)
                {
                    flag =true;
                }
                int t1=t-x;
                if(t1>=g) flag =true;

                if(v[i].size()>v[j].size())
                {
                    if(v[j].size()-g+t1>=x) flag=true;
                }
                else if(v[i].size()==v[j].size())
                {
                    if(v[j].size()-g+t1>=x) flag=true;
                }
                else
                {
                    if(v[i].size()-g+t1>=x) flag=true;
                }
                
            }
            else continue;
        }
    }
    if(flag) cout<<"YES"<<endl;
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