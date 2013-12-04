#include <cstdio>

long n,a[1001],b,c=1,i,j,u[1001];

long gcd(long a,long b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}

int main ()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%ld",&a[i]);
	for(i=1;i<=n;i++)
	{
		if(u[i])continue;
		b=0; j=i;
		while(! u[j])
		{
			b++;
			u[j]=1;
			j=a[j];
		}
		
		c=c*b/gcd(b,c);
	}
	printf("%d\n",c);
	
	return 0;
}