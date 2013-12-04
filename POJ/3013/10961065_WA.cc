#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 50010
#define M 100010
int head[N],cnt,vis[N];
long long d[N];
struct edge
{	int v,next; long long w;	}e[M];
int n,m;		int heap[N],lh;
void addedge(int u,int v,long long w)
{	e[cnt].next=head[u];	e[cnt].v=v;	e[cnt].w=w;	head[u]=cnt++;		}
void build_down(int s)
{
	int father=s,son=s*2;
	if(son+1<=lh && d[heap[son]]>d[heap[son+1]])son++;
	while (son<=lh)
	{
		if(d[heap[father]]>d[heap[son]])
		{
			swap(vis[heap[father]],vis[heap[son]]);
			swap(heap[father],heap[son]);
			father=son;		son=father*2;
			if(son+1<=lh && d[heap[son]]>d[heap[son+1]])son++;
		}else return;
	}
}
void build_up(int s)
{
	int son=s,father=s/2;
	while (father>=1)
	{
		if(d[heap[father]]>d[heap[son]])
		{
			swap(vis[heap[father]],vis[heap[son]]);
			swap(heap[father],heap[son]);
			son=father;		father=son/2;
		}else return;
	}
}
void spfa(int s)
{
	memset(d,-1,sizeof(d));
	memset(vis,0,sizeof(vis));
	lh=0;	vis[s]=1; heap[++lh]=s; d[s]=0;
	while (lh>0)
	{
		int now=heap[1];	vis[now]=0;	heap[1]=heap[lh--];	vis[heap[1]]=1;build_down(1);
		for(int i=head[now];i!=-1;i=e[i].next)
		{
			int v=e[i].v;
			if(d[v]==-1 || d[v]>d[now]+e[i].w)
			{
				d[v]=d[now]+e[i].w;
				if(! vis[v])
				{	heap[++lh]=v;		vis[v]=lh;		build_up(lh);		}
				else
					if(vis[v]/2>0)
					if(d[v]<d[heap[vis[v]/2]]) build_up(vis[v]);
			}
		}
	}
}
long long val[N];
int main ()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&val[i]);
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			int u,v;long long w;
			scanf("%d %d %lld",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		spfa(1);
		long long ans=0;
		int i;
		for(i=1;i<=n;i++)
		{
			if(d[i]==-1) break;
			ans+=d[i]*val[i];
		}
		printf("%lld\n",i<=n?-1:ans);
	}
	return 0;
}