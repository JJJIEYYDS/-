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

int n,m,k;
string s;
void solve()
{
    cin>>n>>k;
    cin>>s;
    int l=0,r=0,u=0,d=0;
    int x=0,y=0;
    ll res1=0,res2=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='L') 
        {
            l++;
            x++;
        }
        else if(s[i]=='R')
        {
            r++;
            x--;
        } 
        else if(s[i]=='U')
        {
            u++;
            y++;

        } 
        else
        {
            d++;
            y--;

        }  
        if(abs(x)+abs(y)>abs(res1)+abs(res2))
        {
            res1=abs(x);
            res2=abs(y);
        }
    }

    ll x1=abs(l-r);
    ll y1=abs(u-d);

    

   
    cout<<ans<<endl;



}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;

    while(t--)
      solve();

    system("pause");
    return 0;
}