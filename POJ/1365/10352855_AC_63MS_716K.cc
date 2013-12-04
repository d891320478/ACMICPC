#include <cstdio>
#include <cstring>
bool f[35000];
int a[35000],i,j,x,n,m,lz;
struct
{
	int a,b;
}z[35000];
char ch;
int main ()
{
	a[0]=1; a[1]=2;
	for(i=3;i<=35000;i+=2)
		if(! f[i])
		{
			a[++a[0]]=i;
			for(j=2;i*j<=35000;j++)
				f[i*j]=1;
		}
	while (scanf("%d",&n) && n)
	{
		scanf(" %d%c",&m,&ch);
		x=n;
		for(i=2;i<=m;i++) x*=n;
		while(ch!='\n')
		{
			scanf("%d %d%c",&n,&m,&ch);
			for(i=1;i<=m;i++) x*=n;
		}
		x--;
		memset(z,0,sizeof(z));
		lz=0;
		for(i=1;i<=a[0] && a[i]<=x;i++)
		if(x%a[i]==0)
		{
			z[lz].a=a[i];
			while(x%a[i]==0)
			{
				z[lz].b++;
				x/=a[i];
			}
			lz++;
		}
		printf("%d %d",z[lz-1].a,z[lz-1].b);
		for(i=lz-2;i>=0;i--)
			printf(" %d %d",z[i].a,z[i].b);
		printf("\n");
	}
	
	return 0;
}