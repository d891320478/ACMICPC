#include <cstdio>
#include <cstring>
#define INF (1<<30)
#define N 20010
#define M 900010
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
	else ++ gap[dis[u]=mindis];
	return m-l;
}
int main()
{
	while (scanf("%d%d",&n,&m)!=-1)
	{
		cnt=0;
		memset(head,-1,sizeof(int)*(n+10));
		s=0; t=n+1;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			addedge(s,i,x);
			addedge(i,t,y);
		}
		while (m--)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		for(int i=0;i<=t;i++) cur[i]=head[i];
		memset(dis,0,sizeof(dis));
		memset(gap,0,sizeof(gap));
		n+=2;
		gap[0]=n;
		int ans=0;
		while (dis[s]<n) ans+=sap(s,INF);
		printf("%d\n",ans);
	}
}