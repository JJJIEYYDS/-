#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#define IOS ios::sync_with_stdio(0); \
            cin.tie(0);              \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N=1e6+10;
int a[N];
bool check(int x)
{
    while(x)
    {
        if(x%10==4||x%100==38) return  true;
        x/=10;
    }
    return false;
}

void solve()
{
for(int i=1;i<=N;i++)
    {
        a[i]=a[i-1]+check(i);
    }
    int n,m;
    while(cin>>n>>m)
    {
        if(n==m&&n==0) break;
        cout<<a[m]-a[n-1]<<endl;
    }
    return ;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}

