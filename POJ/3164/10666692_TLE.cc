#include <cstdio>
#include <cmath>
#include <cstring>
#define INF 1e30
#define N 110
int n,m,sum,pre[N];
bool vis[N],cir[N];
struct point
{	double x,y;	}p[N];
double a[N][N],ans;
double dist(point a,point b)
{	return sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0));	}
void dfs(int s)
{
	sum++;	vis[s]=1;
	for(int i=1;i<=n;i++)
		if(a[s][i]<INF && ! vis[i]) dfs(i);
}
void min_arborescence(int n)
{
	int i,j,k;
	while (1)
	{
		for(i=2;i<=n;i++)
		if(! cir[i])
		{
			pre[i]=i;
			a[i][i]=INF;
			for(j=1;j<=n;j++)
				if(! cir[j])
				if(a[j][i]<a[pre[i]][i])pre[i]=j;
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
			if(! cir[j]) if(a[j][i]!=INF)
				a[j][i]-=a[pre[i]][i];
			for(j=pre[i];j!=i;j=pre[j])
			for(k=1;k<=n;k++)
			if(! cir[k])
			{
				a[i][k]=a[i][k]<a[j][k]?a[i][k]:a[j][k];
				if(a[k][j]!=INF)
					a[k][i]=a[k][i]<a[k][j]-a[pre[j]][j]?a[k][i]:a[k][j]-a[pre[j]][j];
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
int main()
{
	int i,j,u,v;
	while (scanf("%d%d",&n,&m)!=-1)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			for(j=1;j<=n;j++) a[i][j]=INF;
		}
		while (m--)
		{
			scanf("%d%d",&u,&v);	a[u][v]=dist(p[u],p[v]);
		}
		memset(vis,0,sizeof(vis));
		sum=0;	dfs(1);
		if(sum<n)
		{	puts("poor snoopy");	continue;	}
		ans=0.0;
		memset(cir,0,sizeof(cir));
		min_arborescence(n);
		printf("%.2f\n",ans);
	}
	
	return 0;
}