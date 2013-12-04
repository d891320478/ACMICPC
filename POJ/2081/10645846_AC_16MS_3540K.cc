#include <cstdio>
bool f[5000010];
int a[500010];
int main ()
{
	f[0]=1;
	for(int i=1;i<=500000;i++)
		if(a[i-1]-i>0 && ! f[a[i-1]-i])
		{
			a[i]=a[i-1]-i;
			f[a[i-1]-i]=1;
		}
		else
		{
			a[i]=a[i-1]+i;
			f[a[i-1]+i]=1;
		}
	int n;
	while (scanf("%d",&n) && n>0)
		printf("%d\n",a[n]);
	
	return 0;
}