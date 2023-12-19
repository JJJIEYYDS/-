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

ll n,m,k;

string s;

ll a[100];

void solve()
{
    cin >> s >> n;

    vector<ll> p;

    reverse(s.begin(),s.end());
    a[0]=1;

    for(int i=1;i<=s.size();i++)
    {
        a[i]=a[i-1]*2;
    }
    ll res=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='?') p.push_back(a[i]);
        else if(s[i]=='1') res+=a[i];
    }

    if(res>n)
    {
        cout<<-1<<endl;
        return ;
    }

    for(int i=p.size()-1;i>=0;i--)
    {
        if(res+p[i]<=n)
        res+=p[i];
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