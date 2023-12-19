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
const int N=5e5+10,INF=0x3f3f3f3f;

int n,m,k;

string s[N];
void solve()
{
    cin>>n;
    map<string,int> mp;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];

        string t=s[i];

        reverse(t.begin(),t.end());

        if(mp.find(s[i])==mp.end()&&mp.find(t)==mp.end())
        {
            mp[s[i]]=1;
        }
    }

    cout<<mp.size()<<endl;

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