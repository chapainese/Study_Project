#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long N=0;
  scanf("%lld",&N);
  long long i=0;
  long long a1[N]={0};
  long long a2[N]={0};
  //�������ұ���
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
  //����������ʱ��������β��㡣
  //���ű���ѭ���������Գ�. 
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
//�ڶ���˳�ű�����������ͷ���
//���α����㹻�ж� 
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




  //��ӡ���
  for(i=0;i<N;i++)
  {
    printf("%lld\n",a2[i]);
  }
  return 0;
}
