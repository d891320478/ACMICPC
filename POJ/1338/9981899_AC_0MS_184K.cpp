#include <cstdio>
#include <cstring>

int main ()
{
	long i=0,a[6000]={1},n,b1=0,b2=0,b3=0;
	while(i<5842)
	{
		long min=2100000000;	
		if(min>a[b1]*2)min=a[b1]*2;
		if(min>a[b2]*3)min=a[b2]*3;
		if(min>a[b3]*5)min=a[b3]*5;
		a[++i]=min;
		if(min==a[b1]*2)b1++;
		if(min==a[b2]*3)b2++;
		if(min==a[b3]*5)b3++;
	}
	while(scanf("%ld",&n) && n)
		printf("%ld\n",a[n-1]);
	
	return 0;
}
