#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m;

vector<pair<int,string>> a;
vector<int> b;

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        a.push_back({i,s});
    }

    cin>>m;

    for(int i=0;i<m;i++)
    { 
        string s;
        cin>>s;

        for(int j=0;j<n;j++)
        {
            string str=a[j].second;
            if(s==str)
            {
                b.push_back(a[j].first);

                for(int k=0;k<a[j].first-1;k++)
                {
                    a[k].first++;
                }

                a[j].first=1;
                sort(a.begin(),a.end());
                break;
            }
        }
    }
    cout<<m<<endl;
    for(auto x:b)
    {
        cout<<x<<endl;
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