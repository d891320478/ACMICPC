#include <cstdio>
int x,y;
int a[100000],b[100000];
void mult(int *a,int b)
{
	for(int i=1;i<=a[0];i++)
	{
		a[i]*=b;
		if(i>1)
		{
			a[i]+=a[i-1]/10;
			a[i-1]%=10;
		}
	}
	while (a[a[0]]>=10)
	{
		a[a[0]+1]=a[a[0]]/10;
		a[a[0]]%=10;
		a[0]++;
	}
}
int com(int *a,int *b)
{
	if(a[0]!=b[0]) return a[0]>b[0];
	for(int i=a[0];i>0;i--)
		if(a[i]!=b[i]) return a[i]>b[i];
	return 1;
}
void minus(int *a,int *b)
{
	for(int i=1;i<=a[0];i++)
	{
		a[i]-=b[i];
		if(a[i]<0) a[i]+=10,a[i+1]--;
	}
	while (a[a[0]]==0 && a[0]>1) a[0]--;
	for(int i=a[0];i>0;i--)
		printf("%d",a[i]);
	printf("\n");
}
int main ()
{
	scanf("%d%d",&x,&y);
	int k=x;
	while (k)
	{
		a[++a[0]]=k%10;
		k/=10;
	}
	k=y;
	while (k)
	{
		b[++b[0]]=k%10;
		k/=10;
	}
	for(int i=2;i<=y;i++)
		mult(a,x);
	for(int i=2;i<=x;i++)
		mult(b,y);
	if(com(a,b)) minus(a,b);
	else printf("-"),minus(b,a);
	return 0;
}
