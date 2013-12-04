#include <cstdio>
#include <cstring>
#define N 1010
int n,m,d[N],a[N][N],i,j,k;
bool vis[N];
int main ()
{
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		if(i==j)a[i][j]=0;
		else a[i][j]=a[j][i]=-1;
	while (m--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(a[u][v]<0 || a[u][v]>w)
			a[u][v]=a[v][u]=w;
	}
	for(i=1;i<=n;i++)
		d[i]=a[1][i];
	d[0]=0;
	vis[1]=1;
	for(i=1;i<n;i++)
	{
		int min=-1;
		for(j=1;j<=n;j++)
			if(! vis[j])
			if(d[j]!=-1)
			if(min==-1 || min>d[j])
			{
				min=d[j];
				k=j;
			}
		vis[k]=1;
		for(j=1;j<=n;j++)
			if(! vis[j])
			if(a[k][j]!=-1)
			if(d[j]==-1 || d[j]>d[k]+a[k][j])
				d[j]=d[k]+a[k][j];
	}
	printf("%d\n",d[n]);
	return 0;
}