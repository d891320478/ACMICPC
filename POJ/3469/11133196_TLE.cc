#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
#define N 20010
#define M 4000010
#define INF (1<<29)
int n,m,s,t;
int head[N],cnt,cur[N],vis[N];
int dis[N],ef[N];
struct edge
{
	int v,w,next;
}e[M];
queue<int> q;
void addedge(int u,int v,int w)
{
	e[cnt]=(edge){v,w,head[u]}; head[u]=cnt++;
	e[cnt]=(edge){u,0,head[v]}; head[v]=cnt++;
}
void push(int u,int i)
{
	int aug=min(e[i].w,ef[u]);
	e[i].w-=aug;
	e[i^1].w+=aug;
	ef[u]-=aug;
	ef[e[i].v]+=aug;
	if(e[i].v!=s && e[i].v!=t && ! vis[e[i].v])
	{
		vis[e[i].v]=1;
		q.push(e[i].v);
	}
}
void relabel(int u)
{
	int mindis=INF;
	for(int i=head[u];i!=-1;i=e[i].next)
	if(e[i].w!=0 && mindis>dis[e[i].v])
	{
		cur[u]=i;
		mindis=dis[e[i].v];
	}
	dis[u]=mindis+1;
}
void discharge(int u)
{
	while(ef[u]>0)
	{
		if(cur[u]==-1) relabel(u);
		int v=e[cur[u]].v,w=e[cur[u]].w;
		if(w>0 && dis[u]==dis[v]+1) push(u,cur[u]);
		cur[u]=e[cur[u]].next;
	}
}
void BFS()
{
	q.push(t); dis[t]=0;
	while(! q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i!=-1;i=e[i].next)
		if(e[i].w==0)
		if(dis[e[i].v]==-1)
		{
			dis[e[i].v]=dis[u]+1;
			q.push(e[i].v);
		}
	}
}
int maxflow(int n)
{
	int i;
	for(i=1;i<=n;i++)
		cur[i]=head[i],dis[i]=-1,ef[i]=vis[i]=0;
	BFS();
	dis[s]=n;
	ef[s]=(1<<30);
	for(i=head[s];i!=-1;i=e[i].next) push(s,i);
	while(! q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		discharge(u);
	}
	return ef[t];
}
int main ()
{
	while(scanf("%d%d",&n,&m)!=-1)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		s=n+1; t=n+2;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			addedge(s,i,x);
			addedge(i,t,y);
		}
		while (m--)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		printf("%d\n",maxflow(n+2));
	}
	
	return 0;
}