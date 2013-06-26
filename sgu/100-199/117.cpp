#include <cstdio>
int n,m,k;
int ans=0;
int fastexp(int a,int b,int n)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%n;
		a=a*a%n;
		b>>=1;
	}
	return ans;
}
int main ()
{
	scanf("%d%d%d",&n,&m,&k);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		if(fastexp(a,m,k)==0) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
