#include <cstdio>

long long a[110][110];
int m,n,i,j;

int main ()
{
	a[0][0]=1;
	for(i=1;i<=100;i++)
	for(j=0;j<=i;j++)
	{
		if(j==0 && j==i)a[i][j]=1;
		else a[i][j]=a[i-1][j-1]+a[i-1][j];
	}
	while (scanf("%d%d",&m,&n))
	{
		if(m==0 && n==0)break;
		printf("%lld\n",a[m][n]);
	}
	
	return 0;
}
