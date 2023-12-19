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
const int N=2e5+10,INF=0x3f3f3f3f;

int n,m,k;

string s;

int a[N],b[N];

void solve()
{
    cin>>n>>s;

    int cnt1=0,cnt2=0;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') cnt1++;
        else cnt2++;
    }

    if(cnt1!=cnt2)
    {
        cout<<-1<<endl;
        return ;
    }

    int idx=0,cnt=0;

    memset(a,0,sizeof a);

    reverse(s.begin(),s.end()); //)()( reverse 之前需要两种颜色，reverse之后需要一种颜色
                                //需要reverse特判
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            b[idx++]=i;
        }
        else 
        {
            if(idx)
            {
                idx--;
                cnt+=2;
            }
        }
    }

    if(cnt==n)
    {
        cout<<1<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<1<<' ';
        }
        cout<<endl;
        return ;
    }

    idx=0,cnt=0;
    reverse(s.begin(),s.end());

    for(int i=0;i<s.size();i++)
    {
         if(s[i]=='(') b[idx++]=i;
         else 
         {
            if(idx)
            {
                idx--;
                a[b[idx]]=true;
                a[i]=true;
                cnt+=2;
            }
         }
    }

    if(cnt==n)
    {
        cout<<1<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<1<<' ';
        }
        cout<<endl;
        return ;
    }
    
    cout<<2<<endl;
    for(int i=0;i<s.size();i++)
    {
        if(a[i])
        {
             cout<<1<<' ';
        }
        else 
        {
            cout<<2<<' ';
        }
    }

    cout<<endl;



    


    
    
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