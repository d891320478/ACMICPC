#include <cstdio>
bool f[50001]={1,1,0};
long long a[50001];
long long n,i,j;
long long f1(long long a)
{
	long long sum=0;
	while (a)
	{
		sum+=a%10;
		a/=10;
	}
	return sum;
}
int main ()
{
	for(i=2;i<=50000;i++)
	if(! f[i])
	{
		a[++a[0]]=i;
		for(j=2;i*j<=50000;j++)
			f[i*j]=1;
	}
	while (scanf("%d",&n) && n)
	{
		for(i=n;;i++)
		{
			long long suma=f1(i),sumb=0,m=i;
			for(j=1;j<=a[0] && m && a[j]<=m;j++)
			{
				while(m%a[j]==0 && m)
				{
					sumb+=f1(a[j]);
					m/=a[j];
				}
			}
			if(m)sumb+=f1(m);
			if(suma==sumb)break;
		}
		printf("%d\n",i);
	}
	
	return 0;
}