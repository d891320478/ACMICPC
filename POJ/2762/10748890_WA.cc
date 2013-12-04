#include <cstdio>
#include <cstring>
#define N 1010
#define M 10000
int n,m,step,tot,color;
int dfn[N],low[N],stack[N],ins[N],vis[N];
int head[N],next[M],e[M],cnt;
int into[N];
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
		memset(into,0,sizeof(into));
		for(int i=1;i<=n;i++)
		for(int j=head[i];j!=-1;j=next[j])
			if(vis[i]!=vis[e[j]])
				into[vis[e[j]]]++;
		int flag=0;
		for(int i=1;i<=color;i++) flag+=(into[i]==0);
		if(flag==1)printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}