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
int a[5000];
string s1[5000],s2[5000];

void solve()
{
    cin>>n>>m;
    map<string,int> mp;

    for(int i=1;i<=n;i++)
    {
        cin>>s1[i];
    }

    for(int i=1;i<=m;i++)
    {
        cin>>s2[i];
    }

    int x=0;
    cin>>x;

    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=m;i++)
    {
        mp[s2[i]]=a[i];
    }

    ll res=0;

    for(int i=1;i<=n;i++)
    {
        if(mp.find(s1[i])==mp.end())
        {
            res+=x;
        }
        else
        {
            res+=mp[s1[i]];
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