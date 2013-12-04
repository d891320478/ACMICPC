#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 1010
#define M 200010
#define INF 1<<30
int head[N],cnt,vis[N],d[N],into[N];
struct edge
{	int v,next,w;	}e[M];
int n,m;		int heap[N],lh;
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
	for(int i=1;i<=n;i++)
	{
		d[i]=INF;
		vis[i]=0;
		into[i]=0;
	}
	into[s]=1;
	lh=0;	vis[s]=1; heap[++lh]=s; d[s]=0;
	while (lh>0)
	{
		int now=heap[1];	vis[now]=0;	heap[1]=heap[lh--];	build_down(1);
		for(int i=head[now];i!=-1;i=e[i].next)
		{
			int v=e[i].v;
			if(d[v]==-1 || d[v]>d[now]+e[i].w)
			{
				d[v]=d[now]+e[i].w;
				if(! vis[v])
				{	heap[++lh]=v;		vis[v]=lh;		build_up(lh);	into[v]++;
				if(into[v]>n)return 0;	}
				else
					if(vis[v]/2>0)
					if(d[v]<d[heap[vis[v]/2]]) build_up(vis[v]);
			}
		}
	}
	return 1;
}
int main ()
{
	char c;
	int i;
	while(scanf("%d%d%c",&n,&m,&c)!=-1)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			int u,v,w;
			char ch;
			scanf("%c",&ch);
			if(ch=='P')
			{
				scanf("%d %d %d%c",&u,&v,&w,&c);
				addedge(u,v,-w);
				addedge(v,u,w);
			}
			else
			{
				scanf("%d %d%c",&u,&v,&c);
				addedge(v,u,-1);
			}
		}
		for(i=1;i<=n;i++) addedge(n+1,i,0);
		if(spfa(n+1))printf("Reliable\n");
		else printf("Unreliable\n");
	}
	return 0;
}