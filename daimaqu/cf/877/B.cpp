#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n;

void solve()
{
    cin>>n;
    vector<int> a;
    int b,c,d;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
        if(x==1) b=i;
        else if(x==2) c=i;
        else if(x==n) d=i;
    }

    if(d>c&&d<b||d<c&&d>b)
    {
        cout<<1<<' '<<1<<endl;
    }
    else 
    {
        int x=max(b,c),y=min(b,c);
        if(d>x)
        {
            cout<<d<<' '<<x<<endl;
        }
        else if(d<y)
        {
            cout<<d<<' '<<y<<endl;
        }
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