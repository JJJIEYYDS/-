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
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;

void solve()
{
    string s;
    cin>>s;

    int t1=-1,ts=-1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0'&&i>ts)
        {
            ts=i;
        }
    }

    bool flag=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1'&&i<ts) flag=true;
    }

    for(int i=0;i<s.size();i++)
    {
        if((s[i]=='/'||s[i]=='?')&&i<ts)
        {
            if(flag)
            {
                if(i==0)
                {
                    s[i]='0';
                }
                else
                {
                    if(s[i-1]=='0'||s[i+1]=='0')
                    {
                        s[i]='0';
                    }
                    else
                    {
                        s[i]='1';
                    }
                }
              
            }
            else s[i]='0';
        }
        if(i>ts&&(s[i]=='/'||s[i]=='?'))
        {
            s[i]='1';
        }
    }

    cout<<s<<endl;
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