#include <cstdio>
#include <cstring>
#include <iostream>

#define N 50010
int head[N],cnt;
int n,m,dp[N][2],ans;
struct edge
{
	int v,w,next;
}e[N<<1];
void addedge(int u,int v,int w)
{
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
void dfs(int u,int f)
{
	dp[u][0]=dp[u][1]=0;
	for(int i=head[u];i!=-1;i=e[i].next)
	if(e[i].v!=f)
	{
		dfs(e[i].v,u);
		if(dp[e[i].v][0]+e[i].w>dp[u][0])
		{
			dp[u][1]=dp[u][0];
			dp[u][0]=dp[e[i].v][0]+e[i].w;
		}
		else if(dp[e[i].v][0]+e[i].w>dp[u][1]) dp[u][1]=dp[e[i].v][0]+e[i].w;
	}
	ans=std::max(ans,dp[u][0]+dp[u][1]);
}
int main ()
{
	while (scanf("%d%d",&n,&m)!=-1)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			int u,v,w;
			char s[3];
			scanf("%d %d %d %s",&u,&v,&w,s);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		ans=0;
		dfs(1,-1);
		printf("%d\n",ans);
	}
	return 0;
}