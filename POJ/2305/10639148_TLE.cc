#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#define SET(a,b) memset(a,b,sizeof(a))
int n,m,a[2000],b[2000],c[2000],d[2000],x,w;
string s;
void mult(int *a,int z,int *b)
{
	int lb=0;
	for(int i=1;i<=a[0];i++)
	{
		b[++lb]=a[i]*z;
		if(b[lb]>1)
		{
			b[lb]+=b[lb-1]/10;
			b[lb-1]%=10;
		}
	}
	while (b[lb]>9)
	{
		b[lb+1]=b[lb]/10;
		b[lb]%=10;
		lb++;
	}
	b[0]=lb;
}
void pls(int *a,int *b)
{
	int la=a[0]>b[0]?a[0]:b[0];
	for(int i=1;i<=la;i++)
	{
		a[i]+=b[i];
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	if(a[la+1]>0)la++;
	a[0]=la;
}
int main ()
{
	while (scanf("%d",&n) && n)
	{
		cin>>s>>m;
		SET(a,0); SET(c,0); SET(d,0);
		a[0]=a[1]=1;
		for(int i=s.size()-1;i>=0;i--)
		{
			SET(b,0);
			mult(a,s[i]-'0',b);
			pls(c,b);
			mult(a,n,a);
		}
		x=0,w=1;
		while (m)
		{
			x+=w*(m%10);
			m/=10;
			w*=n;
		}
		int tmp=0;
		for(int i=c[0];i>=1;i--)
		{
			tmp=tmp*10+c[i];
			tmp%=x;
		}
		if(tmp==0)
		{
			printf("0\n");
			continue;
		}
		while(tmp)
		{
			d[++d[0]]=tmp%n;
			tmp/=n;
		}
		for(int i=d[0];i>0;i--)
			printf("%d",d[i]);
		printf("\n");
	}
	
	return 0;
}