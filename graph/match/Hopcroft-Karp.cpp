#define N 50010
#define M 150010
#define INF (1<<30)
struct edge{	int v,next;	}e[M];	queue<int> q;
int nx,ny,m;	int head[N],cnt,ans;		int cx[N],cy[N];	int dx[N],dy[N];
void addedge(int u,int v){	e[cnt]=(edge){v,head[u]};		head[u]=cnt++;	}
bool bfs()
{	int i,j,k,flag=0,h,t;
	memset(dx,0,sizeof(dx));		memset(dy,0,sizeof(dy));
	while (! q.empty()) q.pop();
	for(i=1;i<=nx;i++) if(cx[i]==-1) q.push(i);
	while (! q.empty())
	{	int i=q.front();		q.pop();
		for(k=head[i];k!=-1;k=e[k].next)
		{	j=e[k].v;
			if(! dy[j])
			{	dy[j]=dx[i]+1;
				if(cy[j]==-1) flag=1; else{	dx[cy[j]]=dy[j]+1;	q.push(cy[j]);	}
			}
		}
	}
	return flag;
}
bool dfs(int u)
{	for(int i=head[u];i!=-1;i=e[i].next)
	{	int v=e[i].v;
		if(dy[v]==dx[u]+1)
		{	dy[v]=0;	if(cy[v]==-1 || dfs(cy[v])){	cx[u]=v;	cy[v]=u;	return 1;	}	}
	}
	return 0;
}
void hopcroft_karp()
{    while(bfs()){	for(int i=1;i<=nx;i++)	if(cx[i]==-1 && dfs(i)) ans++;	}	}
int main()
{	int i,j,u,v;
	while (scanf("%d%d%d",&nx,&ny,&m)!=-1)
	{
		memset(cx,-1,sizeof(cx));	memset(cy,-1,sizeof(cy));
		memset(head,-1,sizeof(head));		cnt=ans=0;
		while (m--){	scanf("%d%d",&u,&v);		addedge(u,v);		}
		hopcroft_karp();		printf("%d\n",ans);
	}
	return 0;
}
