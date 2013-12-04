#include <cstdio>
#include <cstring>
#define INF (1<<30)
#define N 2010
#define M 1000010
int n,m,s,t;
int head[N],gap[N],dis[N],cnt,cur[N];
struct edge
{
	int v,w,next;
}e[M];
void addedge(int u,int v,int w)
{
	e[cnt]=(edge){v,w,head[u]}; head[u]=cnt++;
	e[cnt]=(edge){u,0,head[v]}; head[v]=cnt++;
}
int sap(int u,int m)
{
	if(u==t) return m;
	int l=m;
	for(int &i=cur[u];i!=-1;i=e[i].next)
	if(e[i].w && dis[e[i].v]==dis[u]-1)
	{
		int d=sap(e[i].v,l<e[i].w?l:e[i].w);
		e[i].w-=d;
		e[i^1].w+=d;
		l-=d;
		if(dis[s]==n || !l) return m-l;
	}
	int mindis=n;
	for(int i=cur[u]=head[u];i!=-1;i=e[i].next)
		if(e[i].w && dis[e[i].v]+1<mindis)
		{
			mindis=dis[e[i].v]+1;
			cur[u]=i;
		}
	if(! --gap[dis[u]]) dis[s]=n;
	else ++gap[dis[u]=mindis];
	return m-l;
}
int i,j,a[N],g[N][N],u[N];
int main()
{
    while(scanf("%d%d",&m,&n)!=-1)
    {
	    memset(head,-1,sizeof(head));
		memset(u,0,sizeof(u));
		cnt=0;
    	s=n+1; t=n+2;
    	for(i=1;i<=m;i++)
			scanf("%d",&a[i]);
		for (i=1;i<=n;i++)
		{
			int f;
			scanf("%d",&g[i][0]);
			for(j=1;j<=g[i][0];j++)
				scanf("%d",&g[i][j]);
			scanf("%d",&f);
			addedge(i,t,f);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=g[i][0];j++)
			{
				if(! u[g[i][j]])
				{
					addedge(s,i,a[g[i][j]]);
					u[g[i][j]]=i;
				}
				else
				{
					addedge(u[g[i][j]],i,INF);
					u[g[i][j]]=i;
				}
			}
		}
		n+=2;
		for(int i=1;i<=n;i++) cur[i]=head[i];
		memset(gap,0,sizeof(gap));
		memset(dis,0,sizeof(dis));
		gap[0]=n;
		int ans=0;
		while (dis[s]<n) ans+=sap(s,INF);
		printf("%d\n",ans);
	}
	return 0;
}