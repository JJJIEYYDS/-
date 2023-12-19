#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
const int N=1e5+10,INF=0x3f3f3f3f;

PII p[N];

int b[N];

bool cmp(PII a,PII b)
{
    return a.second<b.second;
}
void solve()
{
    int n,k;

    std::cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        int x;
        std::cin>>x;
        p[i].first=x,p[i].second=i;
    }

    for(int i=1;i<=n;i++) std::cin>>b[i];

    sort(p+1,p+1+n);
    sort(b+1,b+n+1);

    for(int i=1;i<=n;i++)
    {

        p[i].first=b[i];

        //std::cout<<b[i]<<endl;
        
    }

    sort(p+1,p+n+1,cmp);

    for(int i=1;i<=n;i++) std::cout<<p[i].first<<' ';
    std::cout<<endl;
    
}

int main()
{

    int t=1;
    std::cin>>t;

    while(t--)
        solve();

    system("pause");
    return 0;
}