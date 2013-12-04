#include <cstdio>
int n,a[210][210],g[210][210],d[210],i,j,k,ans,sum;
int main ()
{
	while (scanf("%d",&n)!=-1)
	{
		
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			g[i][j]=g[i-1][j]+a[i][j];
		}
		ans=-1600000000;
		for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			for(k=1;k<=n;k++)
				d[k]=g[j][k]-g[i-1][k];
			sum=0;
			for(k=1;k<=n;k++)
			{
				sum+=d[k];
				ans=ans<sum?sum:ans;
				if(sum<0)sum=0;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}