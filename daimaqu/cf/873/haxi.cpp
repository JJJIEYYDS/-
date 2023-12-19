#include <iostream>
#include <cstring>
#include <algorithm>
#include<set>

using namespace std;

const int N=1e5+10,INF=0x3f3f3f3f;

void solve()
{
    int n;

    std::cin>>n;
    string s;
    std::cin>>s;
    set<string> S;
    for(int i=0;i<n;i++)
    {
        string str=s.substr(i,2);
        if(str.size()<2) continue;
        S.insert(str);
    }

    std::cout<<S.size()<<endl;

}

int main()
{

    int t=1;
    cin>>t;

    while(t--)
        solve();

    system("pause");

    return 0;
}