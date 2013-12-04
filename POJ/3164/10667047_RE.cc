#include <cstdio>
#include <cmath>
#include <cstring>
#define INF 1e15
#define N 110
int n,m,cnt,pre[N];
bool vis[N],cir[N];
double a[N][N],ans,x[N],y[N];
double dist(double a,double b,double c,double d)
{	return sqrt((a-b)*(a-b)+(c-d)*(c-d));	}
void min_arborescence()
{
	int i,j,k;
	ans=0.0;
	memset(cir,0,sizeof(cir));
	while (1)
	{
		for(i=2;i<=n;i++)
		if(! cir[i])
		{
			pre[i]=i;
			a[i][i]=INF;
			for(j=1;j<=n;j++)
				if(! cir[j])
				if(a[j][i]<a[pre[i]][i]) pre[i]=j;
		}
		for(i=2;i<=n;i++)
		if(! cir[i])
		{
			j=i;
			memset(vis,0,sizeof(vis));
			while (! vis[j] && j!=1)
			{
				vis[j]=1;
				j=pre[j];
			}
			if(j==1)continue;
			i=j;
			ans+=a[pre[i]][i];
			for(j=pre[i];j!=1;j=pre[j])
			{
				ans+=a[pre[j]][j];
				cir[j]=1;
			}
			for(j=1;j<=n;j++)
			if(! cir[j]) if(a[j][i]<INF)
				a[j][i]-=a[pre[i]][i];
			for(j=pre[i];j!=i;j=pre[j])
			for(k=1;k<=n;k++)
			if(! cir[k])
			{
				if(a[i][k]>a[j][k]) a[i][k]=a[j][k];
				if(a[k][j]<INF)
					if(a[k][i]>a[k][j]-a[pre[j]][j]) a[k][i]=a[k][j]-a[pre[j]][j];
			}
			break;
		}
		if(i>n)
		{
			for(j=2;j<=n;j++)
				if(! cir[j]) ans+=a[pre[j]][j];
			break;
		}
	}
}
void dfs(int u)
{
	vis[u]=1; cnt++;
	for(int i=2;i<=n;i++)
		if(a[u][i]<INF && ! vis[i]) dfs(i);
}
int main()
{
	int i,j,u,v;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",x[i],y[i]);
			for(j=1;j<=n;j++)
				a[i][j]=INF;
		}
		while (m--)
		{
			scanf("%d%d",&u,&v);
			a[u][v]=dist(x[i],x[j],y[i],y[j]);
		}
		memset(vis,0,sizeof(vis));
		cnt=0; dfs(1);
		if(cnt<n) puts("poor snoopy");
		else
		{
			min_arborescence();
			printf("%.2f\n",ans);
		}
	}
	
	return 0;
}