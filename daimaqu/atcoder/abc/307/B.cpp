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

int n,m,k;

string s[1100];

string str[10000];
int cnt;

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            str[++cnt]=s[i]+s[j];
            //cout<<s[i]+s[j]<<endl;
            str[++cnt]=s[j]+s[i];
            //cout<<s[j]+s[i]<<endl;

        }
    }

    
    for(int i=1;i<=cnt;i++)
    {   
        bool flag=0;

        for(int j=0;j<str[i].size();j++)
        if(str[i][j]!=str[i][str[i].size()-j-1])
        {
            flag=true;
            break;
        }

        if(!flag)
        {
            //cout<<i<<endl;
            cout<<"Yes"<<endl;
            return ;
        }
    }

    cout<<"No"<<endl;


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