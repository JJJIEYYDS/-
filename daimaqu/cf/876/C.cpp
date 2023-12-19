#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

void solve()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    
    if(a.back()==1) cout<<"NO"<<endl;
    else 
    {
        vector<int> b;
        cout<<"YES"<<endl;
        int cnt=0;
       for(int i=0;i<n;i++)
       {
        if(a[i]==1) cnt++;
        else 
        {
            b.push_back(cnt);
            cnt=0;
        }
       }
        reverse(begin(b),end(b));
        for(auto x:b)
        {
            
            for(int i=0;i<x;i++)
            {
               cout<<0<<' ';
            }
            cout<<x<<" ";
        }
        cout<<endl;

    }
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