#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long i=0;
	long long count=2021;
	//���ж϶��ٸ�1���� 
	for(count=2021;count>0;)//�����㵽���� 
	{
		i++;
		long long  j=i;
		//�����ж��ٸ�1
		 
		while(j)
		{
			
			//����10�������10%10=0���»���©,�ʽ�������ж������У���ʵ����10������ڴ���ʱ����1������������ʹ������. 
			if(j%10==1)
			{
				if(count)//�ж��Ƿ����;��������� 
				{
				
				count--;
				}
				else
				{
					i-=1;//ƴ�������ô� 
					break;
				}
			}
			
			j/=10;
		}
		
	}
	printf("%lld",i);
	return 0;
	
}
