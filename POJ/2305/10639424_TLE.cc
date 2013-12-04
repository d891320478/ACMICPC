#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#define SET(a,b) memset(a,b,sizeof(a))
long long n,m,a[2000],b[2000],d[2000],x,w,tmp,temp;
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
		SET(a,0); SET(b,0); SET(d,0);
		a[0]=a[1]=1;
		tmp=temp=0;
		for(long long i=s.size()-1;i>=0;i--)
		{
			mult(a,s[i]-'0',b);
			for(long long j=b[0];j>=1;j--)
				tmp=(tmp*10000+b[j])%x;
			temp=(temp+tmp)%x;
			mult(a,n,a);
		}
		if(! temp)
		{
			printf("0\n");
			continue;
		}
		while (temp)
		{
			d[++d[0]]=temp%n;
			temp/=n;
		}
		for(long long i=d[0];i>0;i--)
			printf("%lld",d[i]);
		printf("\n");
	}
	
	return 0;
}