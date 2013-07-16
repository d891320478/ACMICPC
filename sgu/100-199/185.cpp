#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<queue>
using namespace std;
#define INF (1<<30)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 405
#define M 160005
int head[N],cnt;
int n,m,s,t,q[N],start,end;
struct edge
{
	int v,w,next;
}e[M];
int dis[N],g[N][N];
bool vis[N];
void add(int u,int v,int w)
{
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt++;
	e[cnt].v=u;
	e[cnt].w=0;
	e[cnt].next=head[v];
	head[v]=cnt++;
}
bool dij(int s,int t)
{
	for(int i=1;i<=n;++i) dis[i]=g[1][i];
	SET(vis,0);
	dis[s]=0;
	vis[s]=1;
	for(int i=1;i<n;++i)
	{
		int k=0,mn=INF;
		for(int j=1;j<=n;++j)
			if(! vis[j])
			if(dis[j]!=-1)
			if(dis[j]<mn)
			{
				mn=dis[j];
				k=j;
			}
		if(! k) break;
		vis[k]=1;
		for(int j=1;j<=n;++j)
			if(! vis[j] && g[k][j]!=-1)
			if(dis[j]==-1 || dis[k]+g[k][j]<dis[j])
				dis[j]=dis[k]+g[k][j];
	}
	return dis[t]!=1;
}
int cur[N];
int bfs()
{
    memset(dis,-1,sizeof(dis));    start=end=0; q[0]=t; dis[t]=0;
    while (start<=end)
    {
        int u=q[start++];
        for(int i=head[u];i!=-1;i=e[i].next)
        if(dis[e[i].v]==-1 && e[i^1].w>0)  {  dis[e[i].v]=dis[u]+1;   q[++end]=e[i].v;    }
    }
    return dis[s]!=-1;
}
int dfs(int u,int t,int flow)
{
    if(u==t) return flow;    int delta=flow;
    for(int &i=cur[u];i!=-1;i=e[i].next)
        if(dis[u]==dis[e[i].v]+1 && e[i].w>0)
        {
            int d=dfs(e[i].v,t,min(delta,e[i].w));
            e[i].w-=d;    e[i^1].w+=d;   delta-=d;
            if(delta==0) break;
        }
    return flow-delta;
}
int _ans[N];
int dfs0(int u,int f)
{
	if(u==t)
	{
		_ans[++_ans[0]]=u;
		return 1;
	}
	for(int i=head[u];i!=-1;i=e[i].next)
	if(i%2==0)
	if(e[i].w==0)
	if(e[i].v!=f)
	{
		int flag=dfs0(e[i].v,u);
		if(flag)
		{
			_ans[++_ans[0]]=u;
			e[i].w=1;
			return 1;
		}
	}
	return 0;
}
int main ()
{
	scanf("%d%d",&n,&m);
	memset(g,-1,sizeof(g));
	while (m--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u][v]=g[v][u]=w;
	}
	s=n+1,t=n;
	if(! dij(1,n))
	{
		printf("No solution\n");
		return 0;
	}
	cnt=0;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
		if(i!=j)
		if(g[i][j]!=-1)
		if(dis[i]+g[i][j]==dis[j])
			add(i,j,1);
	int ans0=0;
	add(s,1,2);
	while (bfs())
	{
		for(int i=1;i<=n+1;++i) cur[i]=head[i];
		ans0+=dfs(n+1,t,INF);
	}
	if(ans0<2)
	{
		printf("No solution\n");
		return 0;
	}
	_ans[0]=0; dfs0(1,-1);
	for(int i=_ans[0];i>0;--i)
	{
		printf("%d",_ans[i]);
		if(i>1) printf(" ");
		else printf("\n");
	}
	_ans[0]=0; dfs0(1,-1);
	for(int i=_ans[0];i>0;--i)
	{
		printf("%d",_ans[i]);
		if(i>1) printf(" ");
		else printf("\n");
	}
	return 0;
}
