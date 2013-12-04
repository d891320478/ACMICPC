#include <cstdio>
#include <cstring>

int t,m,n,p;
int g[210][210],u[210],h[210],q[210],va;

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

int main ()
{
	while(scanf("%d%d%d",&m,&n,&p))
	{
		int z[210][210]={0};
		
		if(m==0 && n==0 && p==0)break;
		for(int i=1;i<=p;i++)
		{
			int j,k;
			scanf("%d %d",&j,&k);
			z[j][k]=1;
		}
		memset(g,0,sizeof(g));
		memset(u,0,sizeof(u));
		memset(h,0,sizeof(h));
		memset(q,0,sizeof(q));
		va=0;
		for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(! z[i][j])
			{
				g[i][++g[i][0]]=j;
				if(! u[g[i][g[i][0]]])
				if(! h[i])
				{
				    va++;
				    h[i]=g[i][g[i][0]];
				    q[g[i][g[i][0]]]=i;
				    u[g[i][g[i][0]]]=1;
				}
			}
		for(int i=1;i<=m;i++)
		if(! h[i])
		{
			memset(u,0,sizeof(u));
			if(dfs(i))va++;
		}
		t++;
		printf("Case %d: %d\n",t,m+n-va);
	}

	return 0;
}