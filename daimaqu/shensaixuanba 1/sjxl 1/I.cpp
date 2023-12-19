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


int rp(int n)
{
    int i=0,r=1;
    do
    {
        r*=10;
        a[i++]=r/n;
        r%=n;
    }
    while(r!=1)
    return i;
}
void solve()
{
    cin>>n>>m;

    k=rp(n);

    cout<<a[(m-1)%k]<<endl;


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
