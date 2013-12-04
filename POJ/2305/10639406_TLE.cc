#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#define SET(a,b) memset(a,b,sizeof(a))
long long n,m,a[2000],b[2000],c[2000],d[2000],x,w,tmp;
string s;
void mult(long long *a,long long z,long long *b)
{
	long long lb=0;
	for(long long i=1;i<=a[0];i++)
	{
		b[++lb]=a[i]*z;
		if(b[lb]>1)
		{
			b[lb]+=b[lb-1]/10000;
			b[lb-1]%=10000;
		}
	}
	while (b[lb]>9999)
	{
		b[lb+1]=b[lb]/10000;
		b[lb]%=10000;
		lb++;
	}
	b[0]=lb;
}
void pls(long long *a,long long *b)
{
	long long la=a[0]>b[0]?a[0]:b[0];
	for(long long i=1;i<=la;i++)
	{
		a[i]+=b[i];
		a[i+1]+=a[i]/10000;
		a[i]%=10000;
	}
	if(a[la+1]>0)la++;
	a[0]=la;
}
int main ()
{
	while (scanf("%d",&n) && n)
	{
		cin>>s>>m;
		x=0,w=1;
		while (m)
		{
			x+=w*(m%10);
			m/=10;
			w*=n;
		}
		SET(a,0); SET(c,0); SET(d,0);
		a[0]=a[1]=1;
		tmp=0;
		for(long long i=s.size()-1;i>=0;i--)
		{
			SET(b,0);
			mult(a,s[i]-'0',b);
			pls(c,b);
			for(long long j=c[0];j>=1;j--)
				tmp=(tmp*10000+c[j])%x;
			if(! tmp) c[0]=1;
			else c[0]=0;
			while (tmp)
			{
				c[++c[0]]=tmp%10000;
				tmp/=10000;
			}
			mult(a,n,a);
		}
		tmp=0;
		for(long long i=c[0];i>0;i--)
			tmp=tmp*10000+c[i];
		if(! tmp)
		{
			printf("0\n");
			continue;
		}
		while (tmp)
		{
			d[++d[0]]=tmp%n;
			tmp/=n;
		}
		for(long long i=d[0];i>0;i--)
			printf("%lld",d[i]);
		printf("\n");
	}
	
	return 0;
}