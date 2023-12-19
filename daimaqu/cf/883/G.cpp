#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;
string str;

struct node
{
    int d;
    string g,x;
}a[N];

struct tc
{
    int d;
    string s;
    bool operator<(const tc &p) const
    {
        return d>p.d;
    }
};

void solve()
{
    cin>>n>>m>>str;

    map<string,ll> mp;

    for(int i=1;i<=m;i++)
    {
        cin>>a[i].d>>a[i].g>>a[i].x;
    }

    priority_queue<tc> p;

    p.push({0,str});

    string mb;

    for(int i=0;i<n;i++)
    {
        mb+='0';
    }

    while(p.size())
    {
        tc t=p.top();
        p.pop();
        
        ll dist=t.d;
        string s=t.s;

        if(s==mb) 
        {
            cout<<dist<<endl;
            return;
        }

        for(int i=1;i<=m;i++)
        {   
            string temp;
            for(int j=0;j<n;j++)
            {
                if(a[i].g[j]=='1')
                {
                    temp+='0';
                }
                else if(a[i].x[j]=='1'||s[j]=='1')
                {
                    temp+='1';
                }
                else temp+='0';
            }
            if(mp.find(temp)==mp.end())
            {
                p.push({dist+a[i].d,temp});
                mp[temp]=dist+a[i].d;
            }
            else if(mp[temp]>dist+a[i].d)
            {
                mp[temp]=dist+a[i].d;
                p.push({dist+a[i].d,temp});

            }
        }

    }
    cout<<-1<<endl;

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