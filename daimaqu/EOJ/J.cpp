#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;
const int N=2e6+10,INF=0x3f3f3f3f;

int n,m;

char s[N];

void solve()
{
    
    string t;
    cin>>n>>s;

    int l=0,r=n - 1, x=n;

    while (l <= r){
        bool f = 0;
        for (int i = 0; l + i <= r - i; i++){
            if (s[l + i] > s[r - i]){
                f = 1;
                break;
            }
            else if(s[l + i] < s[r - i]){
                break;
            }
        }
        if (f) t += s[r--];
        else t += s[l++];
    }


    

    cout<<t<<endl;
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