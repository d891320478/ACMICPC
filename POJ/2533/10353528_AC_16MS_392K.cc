#include <cstdio>
int n,a[1001],b[1001],amx=1;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=1;
		for(int j=1;j<i;j++)
			if(a[j]<a[i] && b[j]+1>b[i])b[i]=b[j]+1;
		amx=amx>b[i]?amx:b[i];
	}
	printf("%d\n",amx);
	return 0;
}