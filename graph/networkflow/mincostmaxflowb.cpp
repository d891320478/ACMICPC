#define N 1010
#define M 1000010
#define INF (1<<30)
int n,m,s,t,ans;
int head[N],d[N],pre[N],cnt;
bool vis[N];
struct edge
{
	int v,w,c,next;
}e[M];
void addedge(int u,int v,int w,int c)
{
	e[cnt]=(edge){v,w,c,head[u]}; head[u]=cnt++;
	e[cnt]=(edge){u,0,-c,head[v]}; head[v]=cnt++;
}
int spfa()
{
	queue<int> q;
	memset(pre,-1,sizeof(pre));
	memset(d,-1,sizeof(d));
	d[s]=0;
	q.push(s);
	while (! q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i!=-1;i=e[i].next)
		if(e[i].w)
		if(d[e[i].v]==-1 || d[e[i].v]>d[u]+e[i].c)
		{
			d[e[i].v]=d[u]+e[i].c;
			pre[e[i].v]=i;
			if(! vis[e[i].v]) q.push(e[i].v),vis[e[i].v]=1;
		}
	}
	return d[t]!=-1;
}
void mcmf()
{
	ans=0;
	while (spfa())
	{
		int u,mn=INF;
		for(u=t;u!=s;u=e[pre[u]^1].v)
			mn=min(mn,e[pre[u]].w);
		ans+=mn*d[t];
		for(u=t;u!=s;u=e[pre[u]^1].v)
			e[pre[u]].w-=mn,e[pre[u]^1].w+=mn;
	}
}
