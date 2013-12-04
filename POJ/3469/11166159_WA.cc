#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define INF (1<<30)
#define N 21000
#define M 900010
#pragma comment(linker, "/STACK:32000000")
int n,m,s,t;
int head[N],cur[N],cnt;
struct edge
{
	int v,w,next;
}e[M];
int q[N],dis[N],start,end;
void addedge(int u,int v,int w)
{
	e[cnt]=(edge){v,w,head[u]}; head[u]=cnt++;
	e[cnt]=(edge){u,0,head[v]}; head[v]=cnt++;
}
int bfs()
{
	memset(dis,-1,sizeof(dis));
	start=end=0; q[0]=t; dis[t]=0;
	while (start<=end)
	{
		int u=q[start++];
		for(int i=head[u];i!=-1;i=e[i].next)
			if(dis[e[i].v]==-1 && e[i^1].w>0)
			{
				dis[e[i].v]=dis[u]+1;
				q[++end]=e[i].v;
			}
	}
	return dis[s]!=-1;
}
int dfs(int u,int t,int flow)
{
	if(u==t) return flow;
	int delta=flow;
	for(int &i=cur[u];i!=-1;i=e[i].next)
		if(dis[u]==dis[e[i].v]+1 && e[i].w>0)
		{
			int d=dfs(e[i].v,t,min(flow,e[i].w));
			e[i].w-=d;
			e[i^1].w+=d;
			delta-=d;
			if(delta==0) break;
		}
	if(flow==delta) dis[u]=-1;
	return flow-delta;
}
int main()
{
	while (scanf("%d%d",&n,&m)!=-1)
	{
		s=n+1; t=n+2; cnt=0;
		memset(head,-1,sizeof(head));
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
		int ans=0;
		while (bfs())
		{
			for(int i=1;i<=t;i++) cur[i]=head[i];
			ans+=dfs(s,t,INF);
		}
		printf("%d\n",ans);
	}
	return 0;
}