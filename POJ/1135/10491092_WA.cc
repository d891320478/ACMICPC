#include <cstdio>
#include <cstring>
int n,m,vis[510],i,j,k,l;
double dis[510],a[510][510];
int main ()
{
	int tt=0;
	while (scanf("%d%d",&n,&m))
	{
		if(n==0 && m==0) break;
		tt++;
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j)a[i][j]=-1;
			else a[i][j]=0;
		while (m--)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			a[u][v]=a[v][u]=w;
		}
		for(i=1;i<=n;i++)
			dis[i]=a[1][i],vis[i]=0;
		vis[1]=1;
		for(i=1;i<n;i++)
		{
			double mn=1600000000;
			for(j=1;j<=n;j++)
				if(! vis[j])
				if(mn>dis[j] && dis[j]!=-1)
				{
					k=j;
					mn=dis[j];
				}
			vis[k]=1;
			for(j=1;j<=n;j++)
				if(! vis[j])
				if(a[k][j]!=-1)
				if(dis[j]==-1 || dis[j]>dis[k]+a[k][j])
					dis[j]=dis[k]+a[k][j];
		}
		double mx=0,time=0;
		int sum=0;
		for(i=1;i<=n;i++)
			if(mx<dis[i]) mx=dis[i];
		for(i=1;i<=n;i++)
			if(mx==dis[i]){sum++; k=i;}
		printf("System #%d\n",tt);
		if(n==1)
		{
			printf("The last domino falls after 0.0 seconds, at key domino 1.\n");
			continue;
		}
		if(sum==1)printf("The last domino falls after %.1f seconds, at key domino %d.\n",mx,k);
		else
		{
			for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				if(dis[i]==mx && dis[j]==mx)
				if(a[i][j]!=-1)
				if(a[i][j]>time)
				{
					k=i,l=j;
					time=a[i][j];
				}
			printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n",mx+time/2,k,l);
		}
	}
	
	return 0;
}