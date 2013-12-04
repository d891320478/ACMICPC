#include <cstdio>
#include <cmath>
#include <cstdlib>
int a,b,n;
int main ()
{
	while (scanf("%d%d",&b,&n) && b && n)
	{
		a=(int)exp((log((double)b)/(n*1.0)));
		printf("%d\n",abs((int)(pow(a,n)-b))<abs((int)(pow(a+1,n)-b))?a:a+1);
	}
	
	return 0;
}