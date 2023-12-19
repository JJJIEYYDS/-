#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef pair<int,int> PII;
const int N=1e5+10,INF=0x3f3f3f3f;
double a[N],b[N],w[N];
int n,k;

bool check(double x)
{
    for(int i=1;i<=n;i++)
    {
        w[i]=b[i]-a[i]*x;
    }

    sort(w+1,w+n+1,greater<double>());
    double res=0;
    for(int i=1;i<=k;i++) res+=w[i];
    return res>=0;
    
}
void solve()
{
   
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }

    double l=0,r=1e9;

    while(r-l>1e-6)
    {
        
        double mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }

    cout<<fixed<<setprecision(2)<<l<<endl;
}

int main()
{

    int t=1;
    cin>>t;

    while(t--)
      solve();

    //system("pause");
    return 0;
}
0/1 分数规划
// 本题可以抽象成给定n对整数和a[i],b[i]，从中选出若干对，使选出的数对的之和
// 与之和的商最大。

// 不妨猜测一个值，然后考虑这样一个问题，是否存在一种方案使得成立。

// 如果存在这样的方案使得成立，那么变形得进一步可知： 成立。也就是说，比我们求的最大值要小。

// 如果对于任意一种情况，都有成立，那么变形之后可以得到成立。也就是说，比我们求的最大值要大。

// 这与“二分答案”的情形非常相似,即本题的答案满足单调性。虽然最终的答案是未知的，但是如果我
// 一个值，就能通过判定是否存在一组解满足来确定应该变得更大还是更小。也就是说，解的存在具有单调性。

// 如何判定“是否存在一组解满足呢？显然，我们只需要判定这个式子的最大值是否为非负的。这个判定问题显然比原问题要简单得多，因为；可以直接求出。这就等价于从n个数里选出若干个，使它们的和最大。

// 综上所述，我们可以二分答案来求解本题。