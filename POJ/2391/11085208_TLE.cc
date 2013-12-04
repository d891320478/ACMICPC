#include<stdio.h>
#include <queue>
#include<string.h>
#include <iostream>
using namespace std;
#define N 210
#define M 800010
#define INF (0x7fffffff)
long long n,m,s,t,ans;
long long head[N],cnt,dis[N];
struct edge{	long long v,next; long long w; }e[M];
void addedge(long long u,long long v,long long w)
{	e[cnt]=(edge){v,head[u],w}; head[u]=cnt++;
	e[cnt]=(edge){u,head[v],0}; head[v]=cnt++;
}
long long bfs()
{
	queue<long long> q;	while (! q.empty()) q.pop();
	memset(dis,0,sizeof(dis));		dis[s]=1; q.push(s);
	while (! q.empty())
	{
		long long u=q.front(),v;		q.pop();
		for(long long i=head[u];i!=-1;i=e[i].next)
			if(e[i].w && dis[v=e[i].v]==0)
			{	dis[v]=dis[u]+1;	if(v==t) return 1;	q.push(v);	}
	}
	return 0;
}
long long dfs(long long s,long long limit)
{
	if(s==t) return limit;
	long long v;
	long long cost=0,tmp;
	for(long long i=head[s];i!=-1;i=e[i].next)
	if(e[i].w && dis[s]==dis[v=e[i].v]-1)
	{
		tmp=dfs(v,min(limit-cost,(long long)e[i].w));
		if(tmp>0)
		{	e[i].w-=tmp;	e[i^1].w+=tmp;	cost+=tmp;	if(limit==cost) break;
		}else dis[v]=-1;
	}
	return cost;
}
long long u[N],v[N],g[N][N],l,r,mid,mx;
long long sums;
int main ()
{
	scanf("%lld%lld",&n,&m);
	{
		memset(g,-1,sizeof(g));
		sums=0;
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld%lld",&u[i],&v[i]);
			g[i][i]=0;
			sums+=u[i];
		}
		while (m--)
		{
			long long x,y,w;
			scanf("%lld%lld%lld",&x,&y,&w);
			if(g[x][y]==-1 || g[x][y]>w) g[x][y]=g[y][x]=w;
		}
		l=r=0;
		for(long long k=1;k<=n;k++)
		for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
			if(g[i][k]!=-1 && g[k][j]!=-1)
			if(g[i][j]==-1 || g[i][j]>g[i][k]+g[k][j])
				g[i][j]=g[i][k]+g[k][j];
		for(long long i=1;i<=n;i++)
		for(long long j=i+1;j<=n;j++)
			r=max(r,g[i][j]);
		mx=++r;
		while(l<r)
		{
			mid=(l+r)/2;
			cnt=0;
			memset(head,-1,sizeof(head));
			s=n+n+1; t=n+n+2;
			for(long long i=1;i<=n;i++)
			{
				if(u[i]>0)
				{
					addedge(s,i,u[i]);
				}
				if(v[i]>0)
				{
					addedge(i+n,t,v[i]);
				}
				addedge(i,i+n,INF);
			}
			for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++)
				if(g[i][j]>0)
				if(g[i][j]<=mid)
				if(u[i]>0 && v[j]>0)
				{
					addedge(i,j+n,INF);
				}
			long long ans=0;
			while(bfs()) ans+=dfs(s,INF);
			if(ans<sums) l=mid+1;
			else r=mid;
		}
		if(l==mx) printf("-1\n");
		else printf("%d\n",l);
	}
	return 0;
}