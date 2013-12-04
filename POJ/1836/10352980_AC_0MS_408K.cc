#include <cstdio>
int n,b[1001],c[1001];
double a[1001];
int main ()
{
	scanf("%d",&n);
	for (unsigned int i = 1; i <= n; i += 1)
		scanf("%lf",&a[i]);
	b[1]=c[n]=1;
	for(int i=2;i<=n;i++)
	{
		b[i]=1;
		for(int j=1;j<=i-1;j++)
			if(a[j]<a[i] && b[j]+1>b[i])b[i]=b[j]+1;
	}
	for(int i=n-1;i>=1;i--)
	{
		c[i]=1;
		for(int j=n;j>i;j--)
			if(a[j]<a[i] && c[j]+1>c[i])c[i]=c[j]+1;
	}
	int max=1;
	for(int i=1;i<n;i++)
	{
		if(b[i]+c[i]-1>max)max=b[i]+c[i]-1;
		for(int j=i+1;j<=n;j++)
			if(b[i]+c[j]>max)max=b[i]+c[j];
	}
	printf("%d\n",n-max);
	return 0;
}