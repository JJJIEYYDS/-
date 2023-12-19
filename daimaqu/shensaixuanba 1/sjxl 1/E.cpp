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
int s[N];

void solve()
{
    cin>>n>>k;
    
	int res=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(a[i]==1) 
        {
            res++;
        }
        s[i]=res;
    }
    if(res==0) cout<<"Alice"<<endl;
    else if(res==n) 
    {
        if(n%2==0) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
    else{
    for(int i=1;i<=n;i++)   
    {
        if(a[i]!=1)
        {
            if(s[i]%2==0)
            {
                cout<<"Alice"<<endl;
                return ;
            }
            else 
            {
                cout<<"Bob"<<endl;
                return ;
            }
        }
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