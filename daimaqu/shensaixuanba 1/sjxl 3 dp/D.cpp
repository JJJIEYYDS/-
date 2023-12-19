#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cmath>

using namespace std;

typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;
int a,b;
int c[50][50];

void init()
{
    for(int i=0;i<=35;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j||i==j) c[i][j]=1;
            else c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
}


int get(int l)
{
   int sum=0;
    for(int i=0;i<(l-1)/2;i++)
        sum+=c[l-1][i];
    if((l-1)%2!=0)
        sum+=c[l-1][(l-1)/2];
    return sum;
}

ll count(int x)
{
    vector<int> v;
    int l=0;
    int y=x;
    while(x)
    {
        v.push_back(x%2);
        x/=2;
        l++;
    }

    reverse(v.begin(),v.end());

    int res=0;

    for(int i=1;i<l;i++)
    {
        res+=get(i);
    }

    int cnt1=0,cnt2=0;
    if(y!=0){
    for(int i=0;i<l;i++)
    {
        if(v[i]==0) cnt1++;
        else cnt2++;
    }

    if(cnt2<=cnt1) res++;
    }

    int zeros=0;
    int ones=1;

    for(int i=1;i<l;i++)
    {
        zeros++;
        if(v[i]==1)
        {
            int m=l-2*zeros;
            if(m>=0)
            {
                if(m%2==0)
                {
                    m/=2;
                }
                else m=m/2+1;
            }
            else m=0;

            for(int j=m;j<=l-zeros-ones;j++)
            {
                res+=c[l-zeros-ones][j];
            }
            ones++;
            zeros--;
        }
    }
    return res;

}

void solve()
{
    init();
    cin >> a >> b;

    cout<<count(b)-count(a-1)<<endl;

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