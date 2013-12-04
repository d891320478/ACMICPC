#include <cstdio>
#include <cstring>

int n,m,t;
int g[150][150],u[150],h[150],q[150],va;

int dfs(int i)
{
    for(int j=1;j<=g[i][0];j++)
  		if(! u[g[i][j]])
  		{
   			u[g[i][j]]=1;
   			if( (q[g[i][j]]==0) || (dfs(q[g[i][j]])) )
   			{
    	    	q[g[i][j]]=i;
    			h[i]=g[i][j];
    			return 1;
   			}
  		}
    return 0;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		va=0;
		memset(u,0,sizeof(u));
		memset(g,0,sizeof(g));
		memset(h,0,sizeof(h));
		memset(q,0,sizeof(q));
		for(int i=1;i<=m;i++)
		{
			int j,k;
			scanf("%d%d",&j,&k);
			g[j][++g[j][0]]=k;
		}
		for(int i=1;i<=n;i++)
		{
			memset(u,0,sizeof(u));
			if(dfs(i))va++;
		}
		printf("%d\n",n-va);
	}
	return 0;
}
