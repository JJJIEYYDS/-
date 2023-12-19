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

ll n,m,k;

string s;


ll f(int x)
{
    ll res = 0;

    char a=s[x];
    char b=s[x+1];

    for(int i=x;;i--)
    {
        if(s[i]==a) res++;
        else if(s[i]=='w') res++;
        else break;
    }


    for(int i=x+1;;i++)
    {
        if(s[i]==b) res++;
        else if(s[i]=='w') res++;
        else break;
    }

    return res;
}

void solve()
{
    cin >> n >> s;

    s=s+s+s;

    ll ans = -1;

    for(int i=n;i<2*n;i++)
    {
        if(s[i]==s[i+1]) continue;

        if(s[i]=='w')
        {
            s[i]='r';
            ans=max(ans,f(i));
            s[i]='b';
            ans=max(ans,f(i));
            s[i]='w';
        }
        ans = max(ans, f(i));
    }

    ans = min(ans,n);// wrrr

    if(ans==-1)
    {
        ans=n;
    }

    cout<<ans<<endl;
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