#include <cstdio>
#include <cmath>
long long a[40000],s[40000],ls,i,n;
long long f(long long n)
{
	long long i,j;
	for(i=1;s[i]<n;i++);
	n-=s[i-1];
	for(j=1;;j++)
	{
		if(n-(long long)(log10(j*1.0))-1<=0)break;
		n-=(long long)(log10(j*1.0))+1;
	}
	return j/(int)(pow(10,(long long)(log10(j*1.0))+1-n))%10;
}
int main ()
{
	a[0]=s[0]=0;
	for(i=1;s[i-1]<2147483647;i++)
	{
		a[i]=a[i-1]+(long long)(log10(i*1.0))+1;
		s[i]=s[i-1]+a[i];
	}
	ls=i;
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",f(n));
	}
	
	return 0;
}
