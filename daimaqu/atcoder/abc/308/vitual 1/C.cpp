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

int n,m,k;

vector<pair<pair<ll,ll>,int> > v;

bool cmp(pair<pair<ll,ll>,int> a,pair<pair<ll,ll>,int> b)
{
    if(a.first.first*b.first.second==a.first.second*b.first.first) return a.second<b.second;
    return a.first.first*b.first.second>a.first.second*b.first.first;
}
void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back({{x,x+y},i});

    }

    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n;i++)
    {
        cout<<v[i].second<<' ';
    }

    cout<<endl;

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