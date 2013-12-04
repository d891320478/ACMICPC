#include <cstdio>
int m,n,t,a[21][21],i,j;
int main ()
{
	a[0][0]=1;
	for(i=1;i<=20;i++)
	for(j=1;j<=i;j++)
		a[i][j]=a[i-1][j-1]+a[i-j][j];
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&m,&n);
		printf("%d\n",a[m+n][n]);
	}
	
	return 0;
}