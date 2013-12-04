#include <cstdio>
bool f[20001];
int i;
int main ()
{
	for(i=1;i<=10000;i++)
	{
		int sum=i,m=i;
		while (m)
		{
			sum+=m%10;
			m/=10;
		}
		f[sum]=1;
	}
	for(i=1;i<=10000;i++)
		if(! f[i])printf("%d\n",i);
	
	return 0;
}