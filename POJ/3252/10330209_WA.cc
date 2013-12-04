#include <cstdio>
long long s,t,a[33]={0,0};
int i,j;
long long c(int a,int b)
{
	long long ans=1;
	for(int i=1;i<=b;i++)
		ans=ans*(i+a-b)/i;
	return ans;
}
long long f(long long n)
{
	if(n<2)return 0;
	long long ans=1,m=n;
	int ln=0,a0=0,a1=1,b[33];
	while (m)
	{
		ln++;
		ans+=a[ln];
		m>>=1;
	}
	ans-=a[ln];
	for(i=ln;i>=1;i--)
	{
		b[i]=n & 1;
		n>>=1;
	}
	for(i=2;i<=ln;i++)
	{
		if(b[i])
		{
			//if(a0+ln-i>=a1+1)ans++;
			for(j=0;j<=ln-i && a1+j<=ln-(a1+j);j++)
				ans+=c(ln-i,j);
			a1++;
		}
		else a0++;
	}
	return ans;
}
int main()
{
	for(i=2;i<32;i++)
	for(j=1;i-j>=j;j++)
		a[i]+=c(i-1,j-1);
	scanf("%lld%lld",&s,&t);
	printf("%lld\n",f(t)-f(s-1));
	return 0;
}