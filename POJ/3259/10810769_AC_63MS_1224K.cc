#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 30010
#define M 150010
int head[N],cnt,vis[N],d[N];
struct edge
{	int v,next,w;	}e[M];
int n,m1,m2;		int heap[N],lh;
int into[N];
void addedge(int u,int v,int w)
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
int spfa(int s)
{
	memset(d,0x5f,sizeof(d));
	memset(vis,0,sizeof(vis));
	memset(into,0,sizeof(into));
	lh=0; vis[s]=1; heap[++lh]=s; d[s]=0;
	while (lh>0)
	{
		int now=heap[1]; vis[now]=0; heap[1]=heap[lh--]; build_down(1);
		for(int i=head[now];i!=-1;i=e[i].next)
		{
			int v=e[i].v;
			if(d[v]>d[now]+e[i].w)
			{
				d[v]=d[now]+e[i].w;
				if(! vis[v])
				{ ++into[v]; if(into[v]>n) return 0; heap[++lh]=v; vis[v]=lh; build_up(lh); }
				else build_up(vis[v]);
			}
		}
	}
	return 1;
}
int main ()
{
	int tttt;
	scanf("%d",&tttt);
	while(tttt--)
	{
		scanf("%d%d%d",&n,&m1,&m2);
		cnt=0;		memset(head,-1,sizeof(head));
		while (m1--)
		{ int u,v,w; scanf("%d%d%d",&u,&v,&w); addedge(u,v,w); addedge(v,u,w);	}
		while (m2--)
		{ int u,v,w; scanf("%d%d%d",&u,&v,&w); addedge(u,v,-w); }
		if(spfa(1))printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}