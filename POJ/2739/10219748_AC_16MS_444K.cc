#include <cstdio>
bool f[10001]={1,1,0};
int a[1300],sum[1300],i,j,d[10010],n;
int main()
{
	for(i=2;i<=10000;i++)
	if(! f[i])
	{
		a[++a[0]]=i;
		sum[a[0]]=sum[a[0]-1]+a[a[0]];
		for(j=2;i*j<=10000;j++)
			f[i*j]=1;
	}
	for(i=1;i<=a[0];i++)
	for(j=i;j<=a[0];j++)
		if(sum[j]-sum[i-1]<=10000)d[sum[j]-sum[i-1]]++;
	while (scanf("%d",&n) && n)
		printf("%d\n",d[n]);
	
	return 0;
}