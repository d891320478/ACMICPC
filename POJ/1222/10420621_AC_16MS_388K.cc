#include <cstdio>
#include <cstring>
int a[6][7],b[6][7];
int main ()
{
	int t,tt,i,j,k;
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++)
	{
		for(i=1;i<=5;i++)
		for(j=1;j<=6;j++)
			scanf("%d",&a[i][j]);
		memset(b,0,sizeof(b));
		for(k=0;k<=63;k++)
		{
			int q=k,w=1;
			while (q)
			{
				b[1][w++]=q%2;
				q/=2;
			}
			for(i=2;i<=5;i++)
			for(j=1;j<=6;j++)
				b[i][j]=(a[i-1][j]+b[i-1][j-1]+b[i-1][j+1]+b[i-2][j]+b[i-1][j])%2;
			int flag=1;
			for(j=1;j<=6;j++)
				if(a[5][j]!=(b[5][j-1]+b[5][j+1]+b[4][j]+b[5][j])%2)
				{
					flag=0;
					break;
				}
			if(flag)break;
		}
		printf("PUZZLE #%d\n",tt);
		for(i=1;i<=5;i++)
		{
			for(j=1;j<6;j++)
				printf("%d ",b[i][j]);
			printf("%d\n",b[i][j]);
		}
	}
	
	return 0;
}