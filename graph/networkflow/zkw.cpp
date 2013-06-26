#define N 1010
#define M 1000010
#define INF (1<<30)
int n,m,s,t,ans,flow,realflow;
int head[N],d[N],cnt;
bool vis[N];
struct edge
{
	int v,w,c,next;
}e[M];
void addedge(int u,int v,int w,int c)
{
	e[cnt].v=v; e[cnt].w=w; e[cnt].c=c; e[cnt].next=head[u]; head[u]=cnt++;
	e[cnt].v=u; e[cnt].w=0; e[cnt].c=-c; e[cnt].next=head[v]; head[v]=cnt++;
}
int aug(int u,int f)
{
	if(u==t)
	{
		ans+=flow*f;
		return f;
	}
	vis[u]=1;
	int tmp=f;
	for(int i=head[u];i!=-1;i=e[i].next)
	if(e[i].w && !e[i].c && !vis[e[i].v])
	{
		int delta=aug(e[i].v,min(e[i].w,tmp));
		e[i].w-=delta;
		e[i^1].w+=delta;
		tmp-=delta;
		if(! tmp) return f;
	}
	return f-tmp;
}
bool spfa(int n)
{
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n;i++) d[i]=INF;
	d[t]=0;
	queue<int> q;
	q.push(t);
	while (! q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i!=-1;i=e[i].next)
			if(e[i^1].w && d[u]-e[i].c<d[e[i].v])
			{
				d[e[i].v]=d[u]-e[i].c;
				if(! vis[e[i].v])
				{
					vis[e[i].v]=1;
					q.push(e[i].v);
				}
			}
	}
	for(int u=1;u<=n;u++)
	for(int i=head[u];i!=-1;i=e[i].next)
		e[i].c+=d[e[i].v]-d[u];
	flow+=d[s];
	return d[s]<INF;
}
void costflow(int n)
{
	int _f;
	while (spfa(n))
		do{
			memset(vis,0,sizeof(vis));
			_f=aug(s,INF);
			realflow+=_f;
		} while (_f);
}
