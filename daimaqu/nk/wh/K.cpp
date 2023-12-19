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

ll i,s;
ll sum;
void solve()
{
    cin>>n;

    while(s<n)
    {
        i+=1;//总天数
        sum+=i;//总人数
        s+=m;//总收集数
    }
    //求出最少天数
    cout<<i<<endl;
    s=0;
    for(ll j=1;j<=i;j++)
    {
        ll h=min((n-s)/(i-j+1),j);

        cout<<h<<' ';

        s+=h*(i-j+1);
        
    }
    
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
   // cin>>t;

    while(t--)
      solve();

    system("pause");
    return 0;
}