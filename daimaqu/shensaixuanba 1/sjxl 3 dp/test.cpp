#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
 
using namespace std;
 
int C[35][35]={0};
 
void init()
{
    for(int i=0;i<=32;i++)
        for(int j=0;j<=i;j++)
            if(!j||i==j)
                C[i][j]=1;
            else
                C[i][j]=C[i-1][j-1]+C[i-1][j];
    return ;
}
 
int total(int l)
{
    int sum=0;
    for(int i=0;i<(l-1)/2;i++)
        sum+=C[l-1][i];
    if((l-1)%2!=0)
        sum+=C[l-1][(l-1)/2];
    return sum;
}
 
int Sum(int x,int flag)
{
    int y=x;
    int a[35]={0};
    int l=0;
    for(int i=0;x!=0;i++)
    {
        a[i]=x%2;
        x/=2;
        l++;
    }
    for(int i=0;i<l/2;i++)
    {
        int temp=a[i];
        a[i]=a[l-i-1];
        a[l-i-1]=temp;
    }//得到x的二进制表示
    int w=0;//w用于统计总数
    for(int i=1;i<l;i++)
       {
       w+=total(i);//得到从1到l之间的round.
       }
    if(flag)//如果是第二个数据，要判断其是否为round
    {
        if(x==0) continue;
        int zeros=0, ones=0;
        for(int i=0;i<l;i++)
            if(a[i]==0)
               zeros++;
            else
                ones++;
        if(zeros>=ones)w++;
    }
    int zeros=0;
    int ones=1;
    for(int i=1;i<l;i++)//计算等长的数中比给定值小的round；
    {
        zeros++;
        if(a[i]==1)
        {
            int m=l-2*zeros;
            if(m>=0)
            {
                if(m%2!=0)
                   m=m/2+1;
                else
                   m=m/2;
            }
            else
                m=0;
            for(int j=m;j<=l-zeros-ones;j++)
                w+=C[l-zeros-ones][j];
            ones++;
            zeros--;
        }
    }
    return w;
}
 
int main()
{
    int a, b;
    init();
    scanf("%d%d",&a,&b);
    int x=Sum(a,0);
    int y=Sum(b,1);
    printf("%d\n",y-x);
    system("pause");
    return 0;
}