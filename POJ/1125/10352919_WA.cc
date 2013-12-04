#include <cstdio>
#include <cstring>
int a[101][101],n,m,i,j,k,ans1,ans2;
int main ()
{
	while (scanf("%d",&n) && n)
	{
		memset(a,-1,sizeof(a));
		for(i=1;i<=n;i++)
		{
			a[i][i]=0;
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				int u,v;
				scanf("%d%d",&u,&v);
				a[i][u]=v;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
		for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][k]!=-1 && a[k][j]!=-1)
			if(a[i][j]==-1 || a[i][j]>a[i][k]+a[k][j])
				a[i][j]=a[i][k]+a[k][j];
		ans2=-1;
		for(i=1;i<=n;i++)
		{
			int max=0;
			for(j=1;j<=n;j++)
				if(a[i][j]!=-1)max=max>a[i][j]?max:a[i][j];
				else break;
			if(j>n) if(ans2==-1 || max<ans2) ans1=i,ans2=max;
		}
		if(ans2==-1)printf("disjoint\n");
		else printf("%d %d\n",ans1,ans2);
	}
	
	return 0;
}