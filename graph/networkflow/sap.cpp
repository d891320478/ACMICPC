#include <cstdio>
#include <cstring>
#define N 20010
#define M 4000010
#define INF 1<<30
struct edge{	int v,w,next;	}e[M];
int cnt,head[N],n,m,s,t,pre[N],cur[N],gap[N],dis[N],ed[N];
void addedge(int u,int v,int w)
{
	if(head[u]==-1) cur[u]=head[u]=cnt;
	else e[ed[u]].next=cnt;
	ed[u]=cnt;	e[cnt].v=v;	e[cnt].next=-1;	e[cnt].w=w;	cnt++;
}
int isap(int n,int s,int t)
{
	int i,flow=0,u=s,aug,v;
	bool flag;
	memset(gap,0,sizeof(gap));
	dis[s]=2; dis[t]=0;	gap[0]=gap[2]=1; gap[1]=n-2;
	for(i=0;i<n;i++)	if(i!=s && i!=t) dis[i]=1;
	while (dis[s]<n)
	{
		if(u==t)
		{
			v=u;	aug=INF;
			while (v!=s){	v=pre[v];	if(aug>e[cur[v]].w) aug=e[cur[v]].w;	}
			flow+=aug;
			while (u!=s){	u=pre[u];	e[cur[u]].w-=aug;	e[cur[u]^1].w+=aug;	}
		}
		for(flag=1,i=cur[u];i!=-1;i=e[i].next)
		if(e[i].w>0 && dis[u]==dis[e[i].v]+1){	cur[u]=i;	flag=0;		break;	}
		if(flag)
		{
			gap[dis[u]]--;	if(gap[dis[u]]==0)return flow;	int mindis=n;
			for(i=head[u];i!=-1;i=e[i].next)
			if(e[i].w>0 && mindis>dis[e[i].v]){	cur[u]=i;	mindis=dis[e[i].v];	}
			gap[dis[u]=mindis+1]++;		if(u!=s) u=pre[u];
		}
		else{	pre[e[i].v]=u;	u=e[i].v;	}
	}
	return flow;
}
int main ()
{
	while(scanf("%d%d",&n,&m)!=-1)
	{
		cnt=0; s=0; t=n+1;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n;i++)
		{	int x,y; scanf("%d%d",&x,&y);
			addedge(s,i,x); addedge(i,s,0); addedge(i,t,y); addedge(t,i,0);
		}
		while (m--)
		{	int u,v,w; scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);	addedge(v,u,w);
		}
		printf("%d\n",isap(n+2,s,t));
	}
	return 0;
}
