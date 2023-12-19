#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<set>
using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,k;
char s[5][5];

void solve()
{
    set<char> st;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>s[i][j];
        }
    }

    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {   
            st.insert(s[i][j]);
        }
        if(st.size()==1)
        {
            for(auto x:st) 
            {
                if(x!='.')
                {
                    cout<<x<<endl;
                    return ;
                }
            }
        }
        st.clear();
    }

    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            st.insert(s[j][i]);
        }
        if(st.size()==1)
        {
            for(auto x:st) 
            {
               if(x!='.')
                {
                    cout<<x<<endl;
                    return ;
                }
            }
        }
        st.clear();
    }

    st.insert(s[1][1]);
    st.insert(s[2][2]);
    st.insert(s[3][3]);

    if(st.size()==1)
    {
            for(auto x:st) 
            {
               if(x!='.')
                {
                    cout<<x<<endl;
                    return ;
                }
            }
    }
    st.clear();

    st.insert(s[3][1]);
    st.insert(s[2][2]);
    st.insert(s[1][3]);
   
    if(st.size()==1)
    {
            for(auto x:st) 
            {
               if(x!='.')
                {
                    cout<<x<<endl;
                    return ;
                }
            }
    }
    st.clear();

    cout<<"DRAW"<<endl;

    


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