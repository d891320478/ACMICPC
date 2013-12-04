#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 1010
int g[N][N],vis[N],n,dfn[N],low[N],step,ans[N];
void dfs(int u,int p)
{
	int s=0,flag=0,sum=0;
	dfn[u]=low[u]=++step;
	vis[u]=1;
	for(int v=1;v<=n;v++)
	if(g[u][v] && v!=p)
	{
		if(! vis[v])
		{
			dfs(v,u);
			s++;
			if(low[v]<low[u])low[u]=low[v];
			if(low[v]>=dfn[u]) flag=1,sum++;
		}
		else if(dfn[v]<low[u])low[u]=dfn[v];
	}
	if(p<0 && s>1) ans[u]=s;
	else if(p>0 && flag) ans[u]=sum+1;
}
int main ()
{
	int ue,ve,ttt=0;
	while (scanf("%d",&ue) && ue)
	{
		memset(vis,0,sizeof(vis));
		memset(g,0,sizeof(g));
		memset(ans,0,sizeof(ans));
		n=0;
		scanf("%d",&ve);
		g[ue][ve]=g[ve][ue]=1;
		n=ue>n?ue:n;
		n=ve>n?ve:n;
		while (scanf("%d",&ue) && ue)
		{
			scanf("%d",&ve);
			g[ue][ve]=g[ve][ue]=1;
			n=ue>n?ue:n;
			n=ve>n?ve:n;
		}
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		step=0;
		for(int i=1;i<=n;i++)
			if(! vis[i]) dfs(i,-1);
		if(ttt>0)printf("\n");
		printf("Network #%d\n",++ttt);
		bool temp=0;
		for(int i=1;i<=n;i++)
			if(ans[i]>1){printf("  SPF node %d leaves %d subnets\n",i,ans[i]);temp=1; }
		if(temp==0)printf("  No SPF nodes\n");
	}
	
	return 0;
}