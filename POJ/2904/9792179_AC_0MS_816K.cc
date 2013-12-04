#include <cstdio>

long f[101][101][11];
int t;

int main ()
{
	for (unsigned int k = 1; k <= 10; k += 1)
	for (unsigned int j = 1; j <= 100; j += 1)
	for (unsigned int i = j; i >= 1; i -= 1)
	{
		if(k==1)
		{
			f[i][j][k]=(i+j)*(j-i+1)/2;
			continue;
		}
		if(j==i)
		{
			f[i][j][k]=j;
			continue;
		}
		long m,min=999999999;
		for (unsigned int l = i+1; l < j; l += 1)
		{
			m=f[i][l-1][k-1]>f[l+1][j][k]?f[i][l-1][k-1]:f[l+1][j][k];
			min=min<m+l?min:m+l;
		}
		f[i][j][k]=min;
	}
	scanf("%d",&t);
	while (t--)
	{
		int k,m;
		scanf("%d%d",&k,&m);
		printf("%ld\n",f[1][m][k]);
	}
	
    return 0;
}
