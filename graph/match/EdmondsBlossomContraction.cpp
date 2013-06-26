#define N 410
#define M 160010
#define SET(a,b) memset(a,b,sizeof(a))
deque<int> q;
int g[N][N],inque[N],inblossom[N];
int match[N],pre[N],base[N];
int findanc(int u,int v)//LCA
{
	bool inpath[N]={0};
	while (1)	{	u=base[u];	inpath[u]=1;	if(match[u]==-1)break;	u=pre[match[u]];	}
	while (1) {	v=base[v];	if(inpath[v]) return v;	v=pre[match[v]];	}
}
void reset(int u,int anc)//压缩花
{	while (u!=anc)
	{	int v=match[u];		inblossom[base[u]]=1;		inblossom[base[v]]=1;
		v=pre[v];		if(base[v]!=anc)pre[v]=match[u];		u=v;
	}
}
void contract(int u,int v,int n)
{	int anc=findanc(u,v);	SET(inblossom,0);	reset(u,anc); reset(v,anc);
	if(base[u]!=anc) pre[u]=v;	if(base[v]!=anc) pre[v]=u;
	for(int i=1;i<=n;i++)
		if(inblossom[base[i]])
		{
			base[i]=anc;
			if(! inque[i])
			{	q.push_back(i);		inque[i]=1;		}
		}
}
bool dfs(int s,int n)
{	for(int i=0;i<=n;i++) pre[i]=-1,inque[i]=0,base[i]=i;
	q.clear();		q.push_back(s);	inque[s]=1;
	while (! q.empty())
	{	int u=q.front();		q.pop_front();
		for(int v=1;v<=n;v++)
			if(g[u][v] && base[v]!=base[u] && match[u]!=v)
				if(v==s || match[v]!=-1 && pre[match[v]]!=-1) contract(u,v,n);
				else if(pre[v]==-1)
				{
					pre[v]=u;
					if(match[v]!=-1) q.push_back(match[v]),inque[match[v]]=1;
					else
					{
						u=v;
						while (u!=-1)
						{ v=pre[u];	int w=match[v]; match[u]=v;	match[v]=u; u=w; }
						return 1;
					}
				}
	}
	return 0;
}
int solve(int n)
{	SET(match,-1);	int ans=0;
	for(int i=1;i<=n;i++)	if(match[i]==-1 && dfs(i,n)) ans++;
	return ans;
}
