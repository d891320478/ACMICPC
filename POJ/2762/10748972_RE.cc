#include <cstdio>
#include <cstring>
#define N 1010
#define M 10000
int n,m,step,tot,color;
int dfn[N],low[N],stack[N],ins[N],vis[N];
int head[N],next[M],e[M],cnt;
int nhead[N],nnext[M],ne[M],ncnt,into[N];
void dfs(int s)
{
	int i,j;
	low[s]=dfn[s]=++step;
	stack[++tot]=s;
	ins[s]=1;
	for(i=head[s];i!=-1;i=next[i])
	{
		if(! dfn[e[i]])
		{
			dfs(e[i]);
			low[s]=low[s]<low[e[i]]?low[s]:low[e[i]];
		}
		else if(ins[e[i]]) low[s]=low[s]<dfn[e[i]]?low[s]:dfn[e[i]];
	}
	if(dfn[s]==low[s])
	{
		color++;
		do{
			j=stack[tot--]; ins[j]=0; vis[j]=color;
		} while(j!=s);
	}
}
bool BFS()
{
	int start=0,tail=-1,q[N],i,s0=0;
	for(i=1;i<=color;i++) if(into[i]==0) {q[++tail]=i;s0++;}
	if(s0>1)return 0;
	while (start<=tail)
	{
		s0=0;
		for(i=nhead[q[start]];i!=-1;i=nnext[i])
		{
			into[ne[i]]--;
			if(into[ne[i]]==0) q[tail++]=ne[i],into[ne[i]]=-1,s0++;
		}
		if(s0>1)return 0;
		start++;
	}
	return 1;
}
int main ()
{
	int tttt;
	scanf("%d",&tttt);
	while (tttt--)
	{
		scanf("%d%d",&n,&m);
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			next[cnt]=head[u];
			e[cnt]=v;
			head[u]=cnt++;
		}
		step=color=tot=0;
		memset(dfn,0,sizeof(dfn));
		for(int i=1;i<=n;i++)
			if(! dfn[i])dfs(i);
		memset(nhead,-1,sizeof(nhead));
		memset(into,0,sizeof(into));
		ncnt=0;
		for(int i=1;i<=n;i++)
		for(int j=head[i];j!=-1;j=next[j])
			if(vis[i]!=vis[e[j]])
			{
				nnext[ncnt]=nhead[vis[i]];
				ne[ncnt]=vis[e[j]];
				nhead[vis[i]]=ncnt++;
				into[vis[e[j]]]++;
			}
		if(BFS())printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}