#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define INF (1<<30)
#define N 2010
#define M 400010
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
	e[cnt].v=v; e[cnt].w=w; e[cnt].next=head[u]; head[u]=cnt++;
	e[cnt].v=u; e[cnt].w=0; e[cnt].next=head[v]; head[v]=cnt++;
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
			int d=dfs(e[i].v,t,min(delta,e[i].w));
			e[i].w-=d;
			e[i^1].w+=d;
			delta-=d;
			if(delta==0) break;
		}
	//if(flow==delta) dis[u]=-1;
	return flow-delta;
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
		int ans0=0;
        while (bfs())
        {
        	for(int i=1;i<=t;i++) cur[i]=head[i];
        	ans0+=dfs(s,t,INF);
        }
        printf("%d\n",ans0);
	}
	return 0;
}