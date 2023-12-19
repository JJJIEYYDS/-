#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;

int a[N];
bool st[300];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int res=0;
    st[0]=true;
    for(int i=1;i<=n;i++)
    {
        a[i]^=a[i-1];
        for(int j=0;j<=256;j++)
        {
            if(st[j])
            {
                res=max(res,j^a[i]);
            }
        }
        st[a[i]]=true;
    }
    memset(st,0,sizeof st);

    cout<<res<<endl;
    
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