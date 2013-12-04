#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 30010
#define M 150010
int head[N],cnt,vis[N];
double d[N];
struct edge
{	int v,next;
	double w1,w2;	}e[M];
int n,m;		int heap[N],lh;
double money;
void addedge(int u,int v,double w1,double w2)
{ e[cnt].next=head[u]; e[cnt].v=v;	e[cnt].w1=w1; e[cnt].w2=w2; head[u]=cnt++;	}
void build_down(int s)
{
	int father=s,son=s*2;
	if(son+1<=lh && d[heap[son]]<d[heap[son+1]])son++;
	while (son<=lh)
	{
		if(d[heap[father]]<d[heap[son]])
		{
			swap(vis[heap[father]],vis[heap[son]]);
			swap(heap[father],heap[son]);
			father=son;		son=father*2;
			if(son+1<=lh && d[heap[son]]<d[heap[son+1]])son++;
		}else return;
	}
}
void build_up(int s)
{
	int son=s,father=s/2;
	while (father>=1)
	{
		if(d[heap[father]]<d[heap[son]])
		{
			swap(vis[heap[father]],vis[heap[son]]);
			swap(heap[father],heap[son]);
			son=father;		father=son/2;
		}else return;
	}
}
int spfa(int s)
{
	for(int i=1;i<=n;i++) d[i]=-1;
	memset(vis,0,sizeof(vis));
	lh=0;	vis[s]=1; heap[++lh]=s; d[s]=money;
	while (lh>0)
	{
		if(d[s]>money)return 1;
		int now=heap[1]; vis[now]=0; heap[1]=heap[lh--]; build_down(1);
		for(int i=head[now];i!=-1;i=e[i].next)
		{
			int v=e[i].v;
			if(d[v]<(d[now]-e[i].w2)*e[i].w1)
			{
				d[v]=(d[now]-e[i].w2)*e[i].w1;
				if(! vis[v])
				{	heap[++lh]=v;		vis[v]=lh;		build_up(lh);		}
				else
					if(vis[v]/2>0)
					if(d[v]<d[heap[vis[v]/2]]) build_up(vis[v]);
			}
		}
	}
	return 0;
}
int main ()
{
	int s;
	while(scanf("%d%d%d%lf",&n,&m,&s,&money)!=-1)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			int u,v;
			double w1,w2,w3,w4;
			scanf("%d%d%lf%lf%lf%lf",&u,&v,&w1,&w2,&w3,&w4);
			addedge(u,v,w1,w2);
			addedge(v,u,w3,w4);
		}
		if(spfa(s))puts("YES");
		else puts("NO");
	}
	return 0;
}