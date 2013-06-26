#include <cstdio>
int n;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main ()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++) ans+=(gcd(n,i)==1);
	printf("%d\n",ans);
	return 0;
}
