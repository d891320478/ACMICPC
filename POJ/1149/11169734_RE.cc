#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define INF (1<<30)
#define N 210
#define M 80010
int head[N],gap[N],dis[N],cnt;
int n,m,s,t;
struct edge
{
	int v,w,next;
}e[M];
void addedge(int u,int v,int w)
{
	e[cnt].next=head[u]; e[cnt].v=v; e[cnt].w=w; head[u]=cnt++;
	e[cnt].next=head[v]; e[cnt].v=u; e[cnt].w=0; head[v]=cnt++;
}
int aug(int u,int m)
{
	if(u==t) return m;
	int flag=0,l=m,d;
	for(int i=head[u];i!=-1;i=e[i].next)
	if(dis[e[i].v]+1==dis[u] && e[i].w>0)
	{
		flag=1;
		d=aug(e[i].v,min(e[i].w,l));
		e[i].w-=d;
		e[i^1].w+=d;
		l-=d;
		if(dis[s]>=n || l==0) return m-l;
	}
	if(! flag)
	{
		int mindis=n;
		for(int i=head[u];i!=-1;i=e[i].next)
			if(e[i].w>0 && dis[e[i].v]<mindis) mindis=dis[e[i].v];
		if(--gap[dis[u]]==0) dis[s]=n;
		else ++gap[dis[u]=mindis+1];
	}
	return m-l;
}
int sap()
{
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	gap[0]=n;
	int ans=0;
	while (dis[s]<n) ans+=aug(s,INF);
	return ans;
}
int a[N],u[N];
int main ()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	memset(u,0,sizeof(u));
	cnt=0;
	memset(head,-1,sizeof(head));
	s=n+1; t=n+2;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		while (k--)
		{
			int j;
			scanf("%d",&j);
			if(! u[j]) addedge(s,i,a[j]);
			else addedge(u[j],i,INF);
			u[j]=i;
		}
		scanf("%d",&k);
		addedge(i,t,k);
	}
	n+=2;
	printf("%d\n",sap());
	
	return 0;
}