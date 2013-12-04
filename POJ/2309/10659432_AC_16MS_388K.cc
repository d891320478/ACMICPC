#include <cstdio>
long long n,a[40],i;
int main ()
{
	a[0]=1;
	for(i=1;i<=35;i++)
		a[i]=a[i-1]*2;
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		long long m=n,sum=0;
		while(m%2==0){m/=2;sum++;}
		printf("%lld %lld\n",n-a[sum]+1,n+a[sum]-1);
	}
	
	return 0;
}