#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 10010
#define INF (1<<30)
int head[N],cnt;
struct edge
{
	int v,w,next;
}e[N<<1];
int n,m,ans;
int dis[N],sz[N],mx[N],root,vis[N],mnx,sum;
void addedge(int u,int v,int w)
{
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
void dfssz(int u,int f)
{
	sz[u]=1;
	mx[u]=0;
	for(int i=head[u];i!=-1;i=e[i].next)
	if(e[i].v!=f && ! vis[e[i].v])
	{
		dfssz(e[i].v,u);
		sz[u]+=sz[e[i].v];
		mx[u]=max(mx[u],sz[e[i].v]);
	}
}
void dfsrt(int u,int size,int f)
{
	mx[u]=max(mx[u],size-sz[u]);
	if(mx[u]<mnx)
	{
		mnx=mx[u];
		root=u;
	}
	for(int i=head[u];i!=-1;i=e[i].next)
	if(e[i].v!=f && ! vis[e[i].v])
		dfsrt(e[i].v,size,u);
}
void dfsdis(int u,int d,int f)
{
	dis[sum++]=d;
	for(int i=head[u];i!=-1;i=e[i].next)
	if(e[i].v!=f && ! vis[e[i].v])
		dfsdis(e[i].v,d+e[i].w,u);
}
int count(int u,int d)
{
	sum=0;
	dfsdis(u,d,0);
	sort(dis,dis+sum);
	int ret=0;
	for(int i=0,j=sum-1;i<j;++i)
	{
		while(dis[j]+dis[i]>m && j>i) --j;
		ret+=j-i;
	}
	return ret;
}
void dfs(int u)
{
	mnx=INF;
	dfssz(u,0);
	dfsrt(u,sz[u],0);
	ans+=count(root,0);
	vis[root]=1;
	for(int i=head[root];i!=-1;i=e[i].next)
	if(! vis[e[i].v])
	{
		ans-=count(e[i].v,e[i].w);
		dfs(e[i].v);
	}
}
int main ()
{
	while (scanf("%d %d",&n,&m) && n+m)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<n;++i)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		memset(vis,0,sizeof(vis));
		ans=0;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}