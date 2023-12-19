#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=110,INF=0x3f3f3f3f;


void solve()
{
    int n;
    cin>>n;

    vector<int> a;
    bool flag=1;
    for(int i=0;i<n;i++) 
    {
        int x;
        cin>>x;
        a.push_back(x);
        if(x<0) 
        {
            if(flag) cout<<x<<endl;
            flag=0;
        }
    }
    sort(a.begin(),a.end());

    if(flag) cout<<a.back()<<endl;

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