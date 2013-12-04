#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
#define N 1010
#define M 50010
#define EPS 1e-4
#define INF 1e20
int head[N],cnt,vis[N];
double d[N],a[N];
struct edge
{	int v,next;
double w;	}e[M];
int n,m;		int heap[N],lh;
int into[N];
void addedge(int u,int v,double w)
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
int spfa(int s,double mid)
{
	for(int i=1;i<=n;i++)
	{
		d[i]=INF;
		vis[i]=into[i]=0;
	}
	lh=0;	vis[s]=1; heap[++lh]=s; d[s]=0;
	while (lh>0)
	{
		int now=heap[1];	vis[now]=0;	heap[1]=heap[lh--];	build_down(1);
		for(int i=head[now];i!=-1;i=e[i].next)
		{
			int v=e[i].v;
			if(d[v]>d[now]+e[i].w*mid-a[now])
			{
				d[v]=d[now]+e[i].w*mid-a[now];
				if(! vis[v])
				{	into[v]++; if(into[v]>n-1) return 0; 
					heap[++lh]=v;		vis[v]=lh;		build_up(lh);		
				}
				else
					if(vis[v]/2>0)
					if(d[v]<d[heap[vis[v]/2]]) build_up(vis[v]);
			}
		}
	}
	return 1;
}
int u,v;
double w;
int main ()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%lf",&a[i]);
	cnt=0;
	memset(head,-1,sizeof(head));
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%lf",&u,&v,&w);
		addedge(u,v,w);
		//addedge(v,u,w);
	}
	double l=0,r=1000,mid;
	while (fabs(r-l)>EPS)
	{
		mid=(l+r)/2;
		if(spfa(1,mid)) r=mid;
		else l=mid;
	}
	printf("%.2f\n",l);
	return 0;
}