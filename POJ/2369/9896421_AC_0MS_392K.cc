#include <cstdio>

long n,a[1001],b[1001]={0},c=1,i;

void sear(long s,long t)
{
	b[s]++;
	if(s!=t)sear(s,a[t]);
}

long gcd(long a,long b)
{
	if(!b)return a;
	else return gcd(b,a%b);
}

int main ()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%ld",&a[i]);
	for(i=1;i<=n;i++)
		sear(i,a[i]);
	for(i=1;i<=n;i++)
		c=c/gcd(c,b[i])*b[i];
	printf("%ld\n",c);
	
	return 0;
}
