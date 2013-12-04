#include <cstdio>
#include <cmath>
int n;
long long a[19][100000],b[100000];
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("2\n");
		return 0;
	}
	if(n==2)
	{
		printf("2\n3\n");
		return 0;
	}
	if(n==3)
	{
		printf("2\n3\n7\n");
		return 0;
	}
	a[1][0]=a[2][0]=a[3][0]=b[0]=1;
	a[1][1]=2;a[2][1]=3;a[3][1]=7;
	b[1]=6;
	for(int k=4;k<=n;k++)
	{
		for(int i=1;i<=a[k-1][0];i++)
		for(int j=1;j<=b[0];j++)
		{
			a[k][i+j-1]+=a[k-1][i]*b[j];
			if(i+j-2>0)
			{
				a[k][i+j-1]+=a[k][i+j-2]/100000000;
				a[k][i+j-2]%=100000000;
			}
		}
		a[k][0]=a[k-1][0]+b[0]-1;
		if(a[k][a[k][0]]>=100000000)
		{
			a[k][a[k][0]+1]=a[k][a[k][0]]/100000000;
			a[k][a[k][0]]%=100000000;
			a[k][0]++;
		}
		for(int j=0;j<=a[k][0];j++)
			b[j]=a[k][j];
		a[k][1]++;
		for(int j=1;j<=a[k][0] && a[k][j]>=100000000;j++)
		{
			a[k][j+1]+=a[k][j]/100000000;
			a[k][j]%=100000000;
		}
		if(a[k][a[k][0]+1]>0)a[k][0]++;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld",a[i][a[i][0]]);
		for(int j=a[i][0]-1;j>0;j--)
		{
			int l=(int)(log(a[i][j])/log(10))+1;
			for(int k=1;k<=8-l;k++)
				printf("0");
			printf("%lld",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
