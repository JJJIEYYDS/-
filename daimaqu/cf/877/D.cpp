#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,p;

void solve()
{
    string s;
    cin>>n>>p>>s;
    int cnt1=0,cnt2=0;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') cnt1++;
        else cnt2++;
    }
    while(p--)
    {
        int x;
        cin>>x;
        x=x-1;
        if(n%2!=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(s[x]==')') s[x]='(',cnt1++,cnt2--;
        else s[x]=')',cnt2++,cnt1--;

        if(cnt1==cnt2)
        {
            if(s[0]!=')'&&s[n-1]!='(') cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;

    while(t--)
      solve();

    system("pause");
    return 0;
}