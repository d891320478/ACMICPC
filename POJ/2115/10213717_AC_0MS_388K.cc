#include <cstdio>
long long a,b,c,k,x,y;
long long z[33];
long long exgcd(long long a,long long b)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	long long d=exgcd(b,a%b);
	long long tmp=x;
	x=y;
	y=tmp-a/b*y;
	return d;
}
int main()
{
	z[0]=1;
	for(int i=1;i<=32;i++)z[i]=z[i-1]*2;
	while (scanf("%lld%lld%lld%lld",&a,&b,&c,&k))
	{
		if(a==0 && b==0 && c==0 && k==0)break;
		long long gcd=exgcd(c,z[k]);
		if((b-a)%gcd)printf("FOREVER\n");
		else
		{
			long long ans=((b-a)/gcd*x%(z[k]/gcd)+(z[k]/gcd))%(z[k]/gcd);
			printf("%lld\n",ans);
		}
	}
	
	return 0;
}