#include <cstdio>

int n;
int a[10001],j,k=1,i;

int main ()
{
	a[1]=1; i=2;
	while(i<=10000)
	{
		k++;
		for(j=1;j<=k;j++)
		{
			if(i<=10000)
			{
				a[i]=a[i-1]+k;
				i++;
			}
			else break;
		}
	}
	while (scanf("%d",&n) && n)
		printf("%d %d\n",n,a[n]);
	
	return 0;
}
