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

string s,t;

void solve()
{
    cin >> s >> t;

    map<char,int> mp1;
    map<char,int> mp2;

    if(s==t)
    {
        cout<<"Yes"<<endl;
        return ;
    } 

    for(int i=0;i<s.size();i++)
    {
        mp1[s[i]]++;
    }

    for(int i=0;i<s.size();i++)
    {
        mp2[t[i]]++;
    }

    ll res1=0,res2=0;

    for(auto x : mp2)
    {
        if(mp1.find(x.first)==mp1.end())
        {
            if(x.first=='a'||x.first=='t'||x.first=='c'||x.first=='o'||x.first=='d'||x.first=='e'||x.first=='r'||x.first=='@')
            {
                if(x.first=='@')
                continue;
                res1+=mp2[x.first];
            }
            else 
            {
                cout<<"No"<<endl;
                return ;
            }
        }
        else
        {
            if(x.first=='a'||x.first=='t'||x.first=='c'||x.first=='o'||x.first=='d'||x.first=='e'||x.first=='r'||x.first=='@')
            {
                if(x.first=='@') continue;

                if(mp1[x.first]==mp2[x.first])
                {
                    continue;
                }
                else if(mp1[x.first]<mp2[x.first])
                {
                    res1+=(mp2[x.first]-mp1[x.first]);
                }
            }
            else 
            {
               if(mp1[x.first]!=mp2[x.first])
               {
                    cout<<"No"<<endl;
                    return ;
               }
            }
        }
    }
    for(auto y:mp1)
    {
        if(mp2.find(y.first)==mp2.end())
        {
            if(y.first=='a'||y.first=='t'||y.first=='c'||y.first=='o'||y.first=='d'||y.first=='e'||y.first=='r'||y.first=='@')
            {
                if(y.first=='@')
                continue;
                res2+=mp1[y.first];
            }
            else 
            {
                cout<<"No"<<endl;
                return ;
            }
        }
        else
        {
            if(y.first=='a'||y.first=='t'||y.first=='c'||y.first=='o'||y.first=='d'||y.first=='e'||y.first=='r'||y.first=='@')
            {
                if(y.first=='@') continue;

                if(mp1[y.first]==mp2[y.first])
                {
                    continue;
                }
                else if(mp2[y.first]<mp1[y.first])
                {
                    res2+=(mp1[y.first]-mp2[y.first]);
                }
            }
            else 
            {
               if(mp1[y.first]!=mp2[y.first])
               {
                    cout<<"No"<<endl;
                    return ;
               }
            }
        }
    }

    if(res1<=mp1['@']&&res2<=mp2['@'])
    {
        if((mp1['@']-res1)==(mp2['@']-res2))
        {
            cout<<"Yes"<<endl;
        }
        else 
        {
            cout<<"No"<<endl;
        }
    }
    else
    {
        cout<<"No"<<endl;
    }

    
    


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