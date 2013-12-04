#include <cstdio>
bool f[100001]={1,1,0};
long long a[100001];
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
	for(i=2;i<=100000;i++)
	if(! f[i])
	{
		a[++a[0]]=i;
		for(j=2;i*j<=100000;j++)
			f[i*j]=1;
	}
	while (scanf("%lld",&n) && n)
	{
		for(i=n;;i++)
		{
			long long suma=f1(i),sumb=0,m=i;
			for(j=1;j<=a[0] && a[j]<=m*m;j++)
			{
				while(m%a[j]==0 && m>1)
				{
					sumb+=f1(a[j]);
					m/=a[j];
				}
				if(m==1)break;
			}
			if(m>1) sumb+=f1(m);
			//printf("%d   %d\n",suma,sumb);
			if(suma==sumb)break;
		}
		printf("%lld\n",i);
	}
	
	return 0;
}