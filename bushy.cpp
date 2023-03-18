#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long N=0;
  scanf("%lld",&N);
  long long i=0;
  long long a1[N]={0};
  long long a2[N]={0};
  //从左向右遍历
  for(i=0;i<N;i++)
  {
    long long j=0;
   for(j=0;j<N;j++)
   {
     a1[j]+=1;
     
   }
   if(a1[i]>a2[i])
   {
     a2[i]=a1[i];
   }
   a1[i]=0;
   
  }
  //反过来遍历时，不遍历尾结点。
  //反着遍历循环条件不对称. 
for(i=N-2;i>=0;i--)
{
  long long j=0;
  for(j=0;j<N;j++)
  {
    a1[j]+=1;
  }
  if(a1[i]>a2[i])
   {
     a2[i]=a1[i];
   }
   a1[i]=0;
}
//第二次顺着遍历，不遍历头结点
//三次遍历足够判断 
for(i=1;i<N;i++)
  {
    long long j=0;
   for(j=0;j<N;j++)
   {
     a1[j]+=1;
     
   }
   if(a1[i]>a2[i])
   {
     a2[i]=a1[i];
   }
   a1[i]=0;
   
  }




  //打印最高
  for(i=0;i<N;i++)
  {
    printf("%lld\n",a2[i]);
  }
  return 0;
}
