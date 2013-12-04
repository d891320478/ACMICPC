#include <cstdio>
long long a,b,c[10000];
long long i,j,ld,x,y,ans=1,ans1;
bool f[10000]={1,1};
long long aa,bb;
struct name
{
	long long x,y;
}d[10000];
long long modexp(long long a,long long b,long long n)
{
	long long t=1,y=a;
	while(b)
	{
		if(b % 2)t=t*y%n;
		y=y*y%n;
		b/=2;
	}
	return t;
}
void exteuclid(long long a,long long b)
{
    long long tmp;
    if(b==0) x=1,y=0;
    exteuclid(b,a%b);
    tmp=x;
    x=y;
    y=tmp-a/b*y;
}
int main()
{
	for(i=2;i<=10000;i++)
	if(! f[i])
	{
		c[++c[0]]=i;
		for(j=2;i*j<=10000;j++)
			f[i*j]=1;
	}
	scanf("%lld%lld",&a,&b);
	for(i=1;i<=c[0];i++)
	{
		if(a%c[i]==0)ld+=1,d[ld-1].x=c[i];
		while(a%c[i]==0)
		{
			a/=c[i];
			d[ld-1].y++;
		}
		if(a==1)break;
	}
	if(a!=1)
	{
		d[ld].x=a;
		d[ld].y=1;
		ld++;
	}
	for(i=0;i<ld;i++)
	{
		if(d[i].x!=2)exteuclid(9901,d[i].x-1);
		else y=1;
		bb=y;
		aa=modexp(d[i].x,d[i].y*b+1,9901);
		ans=ans*((aa-1)*bb%9901)%9901;
	}
	if(ans<0)ans+=9901;
	printf("%lld\n",ans);
	return 0;
}