#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[10010];
int a[100010],b[100010],c[100010];
void div(int *a,int b)
{
	int tmp=0,i;
	for(i=1;i<=a[0] || tmp;i++)
	{
		tmp=tmp*10+a[i];
		a[i]=tmp/b;
		tmp%=b;
	}
	while (a[i]==0 && i>1) i--;
	a[0]=i;
}
void mult(int *a,int b,int *c)
{
	c[0]=a[0];
	for(int i=a[0];i>0;i--)
	{
		c[i]=a[i]*b;
		if(i<a[0])
		{
			c[i]+=c[i+1]/10;
			c[i+1]%=10;
		}
	}
	while (c[c[0]]==0 && c[0]>1) c[0]--;
}
void add(int *b,int *c)
{
	b[0]=max(b[0],c[0]);
	for(int i=c[0];i>0;i--)
	{
		b[i]+=c[i];
		b[i-1]+=b[i]/10;
		b[i]%=10;
	}
	while (b[b[0]]==0 && b[0]>1) b[0]--;
}
int main ()
{
	while (scanf("%s",s)!=-1)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		a[0]=a[1]=1;
		b[0]=1; b[1]=0;
		for(int i=2;s[i];i++)
		{
			div(a,8);
			mult(a,s[i]-'0',c);
			add(b,c);
		}
		printf("%s [8] = 0.",s);
		for(int i=2;i<=b[0];i++) printf("%d",b[i]);
		printf(" [10]\n");
	}
	return 0;
}