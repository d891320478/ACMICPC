#include <cstdio>
#include <cstring>
int head[2010],next[2000010],e[2000010],n,m;
int vis[2010];
bool flag;
bool dfs(int s,int color)
{
	vis[s]=color;
	for(int i=head[s];i!=-1;i=next[i])
		if(! vis[e[i]])
		{
			if(! dfs(e[i],-color))return 0;
		}
		else if(vis[s]==vis[e[i]])return 0;
	return 1;
}
int main ()
{
	int t,tt;
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++)
	{
		scanf("%d%d",&n,&m);
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			next[i*2]=head[u];
			head[u]=i*2;
			e[i*2]=v;
			next[i*2+1]=head[v];
			head[v]=i*2+1;
			e[i*2+1]=u;
		}
		for(int i=1;i<=n;i++)
			if(! vis[i])
			{
				flag=dfs(i,1);
				if(! flag) break;
			}
		if (tt>1)
		{
			printf("\n");
		}
		if(! flag)printf("Scenario #%d:\nSuspicious bugs found!\n",tt);
		else printf("Scenario #%d:\nNo suspicious bugs found!\n",tt);
	}
	
	return 0;
}
