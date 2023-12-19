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

ll n,m,k;
ll lowbit(ll x)
{
    return x&(-x);
}

ll stoint(string s)
{
    ll res=0;

    for(int i=0;i<s.size();i++)
    {
        res=res*2+s[i]-'0';
    }

    return res;
}

void solve()
{
    cin>>n;
    ll m = log2(n)+1;
    ll temp=n;
    ll cnt=0;

    while(temp)
    {
        temp-=lowbit(temp);
        cnt++;
    }
    ll  x = log2(n*2);

    string s;

    s='1';
    cnt-=1;

    for(int i=1;i<x-cnt;i++)
    {
        s+='0';
    }

    while(cnt--)
    {
        s+='1';
    }
    cout<<s<<endl;

    ll y=stoint(s);

    cout<<n-y<<endl;


    


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