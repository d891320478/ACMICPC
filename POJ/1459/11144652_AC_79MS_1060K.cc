#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
#define N 20010
#define M 1600010
#define INF (1<<30)
int n,m,s,t;
int head[N],cnt,cur[N];
int dis[N],ef[N],gap[N];
struct edge{	int v,w,next;	}e[M];
struct vlist
{
	int lh,heap[N];
	void clear()
	{
		lh=0;
	}
	void build_up(int son)
	{
		int father=son/2;
		while (father>=1)
		{
			if(dis[heap[father]]<dis[heap[son]]) swap(heap[father],heap[son]);
			else return;
			son=father;
			father/=2;
		}
	}
	void build_down(int father)
	{
		int son=father*2;
		while (son<=lh)
		{
			if(son+1<=lh && dis[heap[son]]<dis[heap[son+1]]) son++;
			if(dis[heap[father]]<dis[heap[son]]) swap(heap[father],heap[son]);
			else return;
			father=son;
			son*=2;
		}
	}
	void push(int u)
	{
		heap[++lh]=u;
		build_up(lh);
	}
	int top()
	{
		return heap[1];
	}
	void pop()
	{
		heap[1]=heap[lh--];
		build_down(1);
	}
	bool empty(){return lh<=0;}
}list;
queue<int> q;
void addedge(int u,int v,int w)
{
	e[cnt]=(edge){v,w,head[u]}; head[u]=cnt++;
	e[cnt]=(edge){u,0,head[v]}; head[v]=cnt++;
}
void push(int u,int i)
{
	int aug=min(e[i].w,ef[u]),v=e[i].v;
	if(v!=s && v!=t && ef[v]==0) list.push(v);
	e[i].w-=aug;	e[i^1].w+=aug;
	ef[u]-=aug;		ef[v]+=aug;
}
void relabel(int u)
{
	int mindis=INF,nl=dis[u];
	--gap[dis[u]];
	for(int i=head[u];i!=-1;i=e[i].next)
	if(e[i].w!=0 && mindis>dis[e[i].v])	{	cur[u]=i;		mindis=dis[e[i].v];		}
	++gap[dis[u]=mindis+1];
	if(gap[nl]!=0 || nl>=n+1) return;
	for(int i=1;i<=n;i++)
		if(dis[i]>nl && dis[i]<=n && i!=s)
		{
			--gap[dis[i]];
			++gap[n+1];
			dis[i]=n+1;
		}
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
		int u=q.front();	q.pop();
		for(int i=head[u];i!=-1;i=e[i].next)
		if(e[i].w==0 && dis[e[i].v]==-1 && e[i].v!=s)
		{	dis[e[i].v]=dis[u]+1;	q.push(e[i].v);		}
	}
}
int maxflow()
{
	int i;
	for(i=1;i<=n;i++)	cur[i]=head[i],dis[i]=-1,ef[i]=gap[i]=0;
	BFS();	dis[s]=n;	ef[s]=INF;
	for(i=1;i<=n;i++)	if(dis[i]==-1) dis[i]=n;
	for(i=1;i<=n;i++)	gap[dis[i]]++;
	list.clear();
	for(i=head[s];i!=-1;i=e[i].next) push(s,i);
	while(! list.empty())
	{
		int u=list.top();
		list.pop();
		discharge(u);
	}
	return ef[t];
}
int main ()
{
	int n1,n2;
	while (scanf("%d%d%d%d",&n,&n1,&n2,&m)!=-1)
	{
		s=n+1;t=n+2;
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			int u,v,w;
			scanf(" (%d,%d)%d",&u,&v,&w);
			u++,v++;
			addedge(u,v,w);
		}
		while (n1--)
		{
			int u,w;
			scanf(" (%d)%d",&u,&w);
			u++;
			addedge(s,u,w);
		}
		while (n2--)
		{
			int u,w;
			scanf(" (%d)%d",&u,&w);
			u++;
			addedge(u,t,w);
		}
		n+=2;
		printf("%d\n",maxflow());
	}
	
	return 0;
}