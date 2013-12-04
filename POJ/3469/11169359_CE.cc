#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 21000
#define M 900010
#pragma comment(linker, "/STACK:32000000")
int n,m,s,t;
int head[N],cur[N],cnt,dis[N],gap[N];
struct edge
{
	int v,w,next;
}e[M];
void addedge(int u,int v,int w)
{
	e[cnt].next=head[u]; e[cnt].v=v; e[cnt].w=w; head[u]=cnt++;
	e[cnt].next=head[v]; e[cnt].v=u; e[cnt].w=0; head[v]=cnt++;
}
int sap(int u,int limit)
{
	if(u==t) return limit;
	int delta=limit;
	for(int i=cur[u];i!=-1;i=e[i].next)
	if(e[i].w>0 && dis[e[i].v]+1==dis[u])
	{
		cur[u]=i;
		int d=sap(e[i].v,min(delta,e[i].w));
		e[i].w-=d;
		e[i^1].w+=d;
		delta-=d;
		if(dis[s]==n || delta==0) return limit-delta;
	}
	if(limit-delta>0) return limit-delta;
	int mindis=n;
	for(int i=head[u];i!=-1;i=e[i].next)
	if(e[i].w>0 && dis[e[i].v]<mindis)
	{
		mindis=dis[e[i].v];
		cur[u]=i;
	}
	if(--gap[dis[u]]==0) dis[s]=n;
	else ++gap[dis[u]=mindis+1];
	return limit-delta;
}
int main()
{
	while (scanf("%d%d",&n,&m)!=-1)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		s=n+1; t=n+2;
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
		memset(dis,0,sizeof(dis));
		memset(gap,0,sizeof(gap));
		n+=2;
		gap[0]=n;
		int ans=0;
		while (dis[s]<n)
		{
			for(int i=1;i<=n;i++) cur[i]=head[i];
			ans+=sap(s,INF);
		}
		printf("%d\n",ans);
	}
	return 0;
}