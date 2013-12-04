#include <cstdio>
long a,b,c,k,x,y;
long z[33];
long exgcd(long a,long b)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	long d=exgcd(b,a%b);
	long tmp=x;
	x=y;
	y=tmp-a/b*y;
	return d;
}
int main()
{
	z[0]=1;
	for(int i=1;i<=32;i++)z[i]=z[i-1]*2;
	while (scanf("%ld%ld%ld%ld",&a,&b,&c,&k))
	{
		if(a==0 && b==0 && c==0 && k==0)break;
		if(b>=z[k])
		{
			printf("FOREVER\n");
			continue;
		}
		long gcd=exgcd(c,z[k]);
		if((b-a)%gcd)printf("FOREVER\n");
		else
		{
			long ans=(b-a)/gcd*x%(z[k]/gcd);
			ans=(ans+(z[k]/gcd))%(z[k]/gcd);
			printf("%ld\n",ans);
		}
	}
	
	return 0;
}