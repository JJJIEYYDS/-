#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=5e6+10;

int n,m,k;

char s[N],str[N];
int a[N],cnt,idx;


void solve()
{
    cin>>n>>s;

    for(int i=0;i<n;i++)
    {
        str[idx++]=s[i];

        if(s[i]=='(')
        {
            a[cnt++]=idx-1;
        }

        if(s[i]==')'&&cnt)
        {
            idx=a[cnt-1];
            cnt--;
        }
    }
    for(int i=0;i<idx;i++)
    cout<<str[i];
    cout<<endl;
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