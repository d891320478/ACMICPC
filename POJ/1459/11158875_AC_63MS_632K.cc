#include <cstdio>
#include <cstring>
#define INF (1<<30)
#define N 210
#define M 40010
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
int main ()
{
	int n1,n2;
	while (scanf("%d%d%d%d",&n,&n1,&n2,&m)!=-1)
	{
		s=n+1;t=n+2;
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			int u,v,w;
			scanf(" (%d,%d)%d",&u,&v,&w);
			u++,v++;
			addedge(u,v,w);
		}
		while (n1--)
		{
			int u,w;
			scanf(" (%d)%d",&u,&w);
			u++;
			addedge(s,u,w);
		}
		while (n2--)
		{
			int u,w;
			scanf(" (%d)%d",&u,&w);
			u++;
			addedge(u,t,w);
		}
		n+=2;
		for(int i=1;i<=n;i++)
		{
			cur[i]=head[i];
			if(i!=s && i!=t) dis[i]=1;
		}
		dis[s]=2;
		dis[t]=0;
		gap[0]=gap[2]=1; gap[1]=n-2;
		int ans=0;
		while (dis[s]<n) ans+=sap(s,INF);
		printf("%d\n",ans);
	}
	
	return 0;
}