#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;

vector<pair<pair<int,int>,int>> a;

vector<vector<int>> b(110);

bool check(pair<pair<int,int>,int> a,pair<pair<int,int>,int> bb)
{
    int cnt=0;
    for(int i=0;i<a.first.second;i++)
    {
        for(int j=0;j<bb.first.second;j++)
        {
            if(b[a.second][i]==b[bb.second][j]) 
            {
                cnt++;
                break;
            }
        }
    }
    if(bb.first.second==cnt&&a.first.first==bb.first.first) return false;
    return cnt==a.first.second;
    
}
void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back({{x,y},i});
        for(int j=1;j<=y;j++)
        {
            int t;
            cin>>t;
            b[i].push_back(t);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i].first.first>a[j].first.first)
            {
                if(a[i].first.second>a[j].first.second)
                continue;
                if(check(a[i],a[j])) 
                {
                    cout<<"Yes"<<endl;
                    return ;
                }
            }
            else if(a[i].first.first==a[j].first.first)
            {
                if(a[i].first.second==a[j].first.second)
                continue;
                if(a[i].first.second>a[j].first.second)
                {
                    if(check(a[j],a[i])) 
                    {
                        cout<<"Yes"<<endl;
                        return ;
                    }
                }
                else
                {
                    if(check(a[i],a[j])) 
                    {
                        cout<<"Yes"<<endl;
                        return ;
                    }
                }

            }
            else 
            {
                if(a[i].first.second<a[j].first.second)
                continue;
                if(check(a[j],a[i])) 
                {
                    cout<<"Yes"<<endl;
                    return ;
                }
            }
        }
    }

    cout<<"No"<<endl;


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