#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>

using namespace std;

typedef pair<int,int> PII;
const int N=110,INF=0x3f3f3f3f;
int f[N];
void solve()
{
    
    int n,k;
    cin>>n>>k;
  
   cout<<(n-1+k-1)/k+1<<endl;
  
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