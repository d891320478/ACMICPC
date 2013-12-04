#include <cstdio>
#include <cstring>
int n,m;			int g[210][210],u[210],h[210],q[210],va;
int dfs(int i)
{
    for(int j=1;j<=g[i][0];j++)
  	if(! u[g[i][j]])
  	{
   		u[g[i][j]]=1;
   		if( (q[g[i][j]]==0) || (dfs(q[g[i][j]])) )
   		{	q[g[i][j]]=i;	h[i]=g[i][j];	return 1;		}
  	}
    return 0;
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		va=0;
		memset(u,0,sizeof(u));	memset(h,0,sizeof(h));	memset(q,0,sizeof(q));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&g[i][0]);
			for(int j=1;j<=g[i][0];j++)
			{
				scanf("%d",&g[i][j]);
				if(!h[i])
				{
					if(! u[g[i][j]])
					{	    va++;	    h[i]=g[i][j];	    q[g[i][j]]=i;	    u[g[i][j]]=1;}
				}
			}
		}
		for(int i=1;i<=n;i++)
		if(! h[i])
		{	memset(u,0,sizeof(u));	if(dfs(i))va++;	}
		printf("%d\n",va);
	}
	return 0;
}
