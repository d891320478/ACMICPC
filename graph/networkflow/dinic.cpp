#define INF (1<<30)
#define N 101000
#define M 200010
#pragma comment(linker, "/STACK:32000000")
int n,m,s,t;	int head[N],cur[N],cnt;
struct edge{    int v,w,next;	}e[M];
int q[N],dis[N],start,end;
void addedge(int u,int v,int w)
{	e[cnt]=(edge){v,w,head[u]}; head[u]=cnt++;
	e[cnt]=(edge){u,0,head[v]}; head[v]=cnt++;
}
int bfs()
{
    memset(dis,-1,sizeof(dis));    start=end=0; q[0]=t; dis[t]=0;
    while (start<=end)
    {
        int u=q[start++];
        for(int i=head[u];i!=-1;i=e[i].next)
        if(dis[e[i].v]==-1 && e[i^1].w>0)  {  dis[e[i].v]=dis[u]+1;   q[++end]=e[i].v;    }
    }
    return dis[s]!=-1;
}
int dfs(int u,int t,int flow)
{
    if(u==t) return flow;    int delta=flow;
    for(int &i=cur[u];i!=-1;i=e[i].next)
        if(dis[u]==dis[e[i].v]+1 && e[i].w>0)
        {
            int d=dfs(e[i].v,t,min(delta,e[i].w));
            e[i].w-=d;    e[i^1].w+=d;   delta-=d;
            if(delta==0) break;
        }
    return flow-delta;
}
int ans0=0;
while (bfs()){	for(int i=1;i<=n;i++) cur[i]=head[i];		ans0+=dfs(s,t,INF);		}
//--------------------------------------
#pragma comment(linker, "/STACK:32000000")
int n,m,s,t,flow;
int head[N],cur[N],cnt,pre[N],sign;
struct edge
{
	int v,w,next;
}e[M];
int q[N],dis[N],start,end;
void addedge(int u,int v,int w)
{
	e[cnt].v=v; e[cnt].w=w; e[cnt].next=head[u]; head[u]=cnt++;
	e[cnt].v=u; e[cnt].w=w; e[cnt].next=head[v]; head[v]=cnt++;
}
int bfs()
{
	memset(dis,-1,sizeof(dis));
	start=end=0; q[0]=t; dis[t]=0;
	while (start<=end)
	{
		int u=q[start++];
		for(int i=head[u];i!=-1;i=e[i].next)
			if(dis[e[i].v]==-1 && e[i^1].w>0)
			{
				dis[e[i].v]=dis[u]+1;
				q[++end]=e[i].v;
			}
	}
	return dis[s]!=-1;
}
inline void push()
{
	int delta=INF,u;
	for(u=t;u!=s;)
	{
		delta=min(delta,e[pre[u]].w);
		u=e[pre[u]^1].v;
	}
	for(u=t;u!=s;)
	{
		e[pre[u]].w-=delta;
		if(! e[pre[u]].w) sign=e[pre[u]^1].v;
		e[pre[u]^1].w+=delta;
		u=e[pre[u]^1].v;
	}
	flow+=delta;
    
}
void dfs(int u)
{
	if(u==t)
	{
		push();
		return;
	}
	for(int &i=cur[u];i!=-1;i=e[i].next)
		if(dis[u]==dis[e[i].v]+1 && e[i].w>0)
		{
			pre[e[i].v]=i;
			dfs(e[i].v);
			if(dis[sign]>dis[u]) return;
			sign=t;
		}
	dis[u]=-1;
}
flow=0;
while (bfs())
{
	for(int i=1;i<=n;i++) cur[i]=head[i];
	dfs(s);
}
