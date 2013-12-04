#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
typedef unsigned long long ULL;
#define GCC 16381
#define MA ((ULL)1<<63)-1
const ULL cs[]={2,3,5,7,11,13,17,19,23,29};
int t;
ULL n;
//a*b%n----------------------------------------------
inline ULL modmulti(ULL a,ULL b,ULL n)
{
	ULL t=0;
	while (b)
	{
		if(b&1) t=(t+a)%n;
		a=(a+a)%n;
		b>>=1;
	}
	return t;
}
//a^b%n----------------------------------------------
inline ULL modexp(ULL a,ULL b,ULL n)
{
	ULL t=1,y=a%b;
	while(b)
	{
		if(b&1)t=modmulti(t,y,n);
		y=modmulti(y,y,n);
		b>>=1;
	}
	return t;
}
bool MillerRabin(ULL n)
{
	ULL m,u,buf;
	int i,j,k=0;
	for(i=0;i<10;i++)
		if(n==cs[i])return 1;
	if(n<2 || !(n&1))return 0;
	m=n-1;
	while (!(m&1))
		k++,m>>=1;
	for(i=0;i<10;i++)
	{
		u=modexp(cs[i],m,n);
		if(u==1)continue;
		for(j=0;j<k;j++)
		{
			buf=modmulti(u,u,n);
			if(buf==1 && u!=1 && u!=n-1) return 0;
			u=buf;
		}
		if(u-1)return 0;
	}
	return 1;
}
ULL gcd(ULL a,ULL b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
ULL pollard(ULL n)
{
	ULL i=1,x=rand()%(n-1)+1;
	ULL y=x,k=2,d;
	do
	{
		i++;
		d=gcd(n+y-x,n);
		if(d>1 && d<n)return d;
		if(i==k) y=x,k*=2;
		x=(modmulti(x,x,n)+n-GCC)%n;
	} while (y!=x);
	return n;
}
ULL pollard_min(ULL n)
{
	ULL p,a,b=MA;
	if(n==1)return MA;
	if(MillerRabin(n)) return n;
	p=pollard(n);
	a=pollard_min(p);
	b=pollard_min(n/p);
	return a<b?a:b;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lld",&n);
		if(MillerRabin(n))printf("Prime\n");
		else printf("%lld\n",pollard_min(n));
	}
	
	return 0;
}