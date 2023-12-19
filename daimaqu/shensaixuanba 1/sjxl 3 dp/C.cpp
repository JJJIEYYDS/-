#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int a,b;

int get(vector<int> num, int l, int r)
{
    int res = 0;
    
    for(int i = l; i>=r; i--)
    {
        res=res*10 + num[i];
    }
    
    return res;
}

long long count(int n, int x)//从1到n中所有x的数量
{
    if(!n) return 0;
    long long res=0;
    vector<int> num;
    while(n)
    {
        num.push_back(n%10);
        n/=10;
    }
    
    n = num.size();
    
    for(int i = n - 1 - !x; i >= 0; i--)//if x==0 , 从第二位开始
    {
        if(i<n-1)
        {
            res+=get(num,n-1,i+1)*pow(10,i);
            if(!x) res-=pow(10,i);
        }
        
        if(num[i]>x) res += pow(10,i);
        else if(num[i]==x) res += get(num,i-1,0)+1;
    }

    return res;
}

int main()
{
    while(cin>>a>>b&&(a||b))
    {
        if(a>b) swap(a,b);
        
        for(int i = 0; i < 10; i++)
        {
            cout << count(b, i) - count(a-1, i) << ' ';
        }
        cout<<endl;
    }
    
    return 0;
}