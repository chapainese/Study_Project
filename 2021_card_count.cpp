#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long i=0;
	long long count=2021;
	//从判断多少个1改造 
	for(count=2021;count>0;)//从正算到反算 
	{
		i++;
		long long  j=i;
		//计算有多少个1
		 
		while(j)
		{
			
			//考虑10的情况：10%10=0，怕会遗漏,故将其放在判断条件中，但实际上10的情况在处理时会变成1，这样反而会使其多计算. 
			if(j%10==1)
			{
				if(count)//判断是否会中途不够的情况 
				{
				
				count--;
				}
				else
				{
					i-=1;//拼不完整该次 
					break;
				}
			}
			
			j/=10;
		}
		
	}
	printf("%lld",i);
	return 0;
	
}
