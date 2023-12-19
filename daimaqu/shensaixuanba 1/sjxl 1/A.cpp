#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=3e5+10,INF=0x3f3f3f3f;

int n,m;

string s;

void solve()
{
    cin>>s;
    int temp=-1;

    for(int i=s.size()-1;i>=0;i--)
    {
       
        if(s[i]=='A')
        {
            temp=i;
            break;
        }
    }
    
    if(temp==-1) 
    {
        cout<<0<<endl;
        return;
    }
    
    int sum=0;

    for(int i=0;i<temp;i++)
    {
        if(s[i]=='C') 
        {
            s[i]='A';
            sum++;
        }
    }
 
    for(int i=temp;i>=0;i--)
    {
        if(s[i]=='A'&&sum)
        {
            s[i]='C';
            sum--;
        }
    }

    int a=0,b=0,c=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A')
        {
            a++;
        }
        if(s[i]=='B'&&b<a)
        {
            b++;
        }
        if(s[i]=='C'&&c<b)
        {
            c++;
        }
    }
    
   cout<<c<<endl;

    
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
