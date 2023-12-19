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
typedef pair<long long,long long> PLL;
typedef long long ll;


ll n,m,k;

const int N=1e6+10;

bool cmp(PLL a,PLL b)
{
    if(a.first==b.first) return a.second>b.second;
    return a.first>b.first;
}

ll a[N];
PLL v[N];
void solve()
{
    cin >> n >> m;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        res+=a[i];
    }

    for(int i=0;i<m;i++)
    {
        cin>>v[i].first;
    }
    
    for(int i=0;i<m;i++)
    {
        cin>>v[i].second;
    }

    sort(a,a+n);

    sort(v,v+m);


    priority_queue<ll> p;

    for(int i=0,j=0;i<n;i++)
    {
        while(a[i]>=v[j].first&&j<m) 
        {
            p.push(v[j].second);
            j++;
        }

        if(p.size())
        {
            res=res-p.top();
            p.pop();
        }
    }
    cout<<res<<endl;
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
