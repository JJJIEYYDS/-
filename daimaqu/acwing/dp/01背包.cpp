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
const int N=1010;
int v[N],w[N];
int f[N][N];

void solve()
{
	int n,v1;
	
	cin>>n>>v1;
	
	for(int i=1;i<=n;i++) cin>> v[i] >>w[i];
	
	for(int i=i;i<=n;i++ )
	{
		for(int j=0;j<=v1;j++)
		{
			f[i][j]=f[i-1][j];
			if(j>=v[i])
			{
				f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
			}
		}
	}
	
	cout<<f[n][v1]<<endl;
	
	
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}