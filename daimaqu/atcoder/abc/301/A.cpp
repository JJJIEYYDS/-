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
typedef pair<ll,ll> PLL;

const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;

string s;

void solve()
{
    cin >> n >> s;

    PLL cnt1,cnt2;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='T') cnt1.first++,cnt1.second=i;
        else cnt2.first++,cnt2.second=i;
    }

    if(cnt1.first>cnt2.first)
    {
        cout<<"T"<<endl;

    }
    else if(cnt1.first<cnt2.first)
    {
        cout<<"A"<<endl;
    }
    else 
    {
        if(cnt1.second>cnt2.second)
        {
            cout<<"A"<<endl;
        }
        else 
        {
            cout<<"T"<<endl;
        }
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