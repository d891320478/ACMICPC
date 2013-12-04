#include <cstdio>
#include <cstring>
#include <cmath>
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
		bool flag=1;
		m=1;
		for(i=1;i<=n;i++)
			if(mx<dis[i]) {mx=dis[i];m=i;}
		if(tt>1)printf("\n");
		printf("System #%d\n",tt);
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(a[i][j]!=-1)
			if(mx<(dis[i]<dis[j]?dis[i]:dis[j])+(a[i][j]+fabs(dis[j]-dis[i]))/2.0)
			{
				flag=0;
				mx=(dis[i]<dis[j]?dis[i]:dis[j])+(a[i][j]+fabs(dis[j]-dis[i]))/2.0;
				k=i;
				l=j;
			}
		if(! flag)printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n",mx,k,l);
		else printf("The last domino falls after %.1f seconds, at key domino %d.\n",mx,m);
	}
	
	return 0;
}