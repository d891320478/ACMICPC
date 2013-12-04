#include <cstdio>
#include <cstdlib>

int c,g;
int f[21][20002],a[21],b[21];
int i,j,k;

int main ()
{
	scanf("%d%d",&c,&g);
	for(i=1;i<=c;i++)
		scanf("%d",&a[i]);	
	for(i=1;i<=g;i++)
		scanf("%d",&b[i]);
	f[0][10000]=1;
	for(i=1;i<=g;i++)
	for(j=1;j<=20000;j++)
	for(k=1;k<=c;k++)
	{
		f[i][j]+=f[i-1][j-b[i]*a[k]];
	}
	printf("%d\n",f[g][10000]);
	
	return 0;
}
