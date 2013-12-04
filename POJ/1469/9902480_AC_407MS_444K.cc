#include <cstdio>
#include <cstring>

int n,m,t;
int g[110][310],u[310],h[110],q[310],flag;

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
		memset(u,0,sizeof(u));
		memset(h,0,sizeof(h));
		memset(q,0,sizeof(q));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&g[i][0]);
			for(int j=1;j<=g[i][0];j++)
			//{
				scanf("%d",&g[i][j]);
				/*if(! u[g[i][j]])
				if(! h[i])
				{
				    h[i]=g[i][j];
				    q[g[i][j]]=i;
				    u[g[i][j]]=1;
				}
			}*/
		}
		flag=1;
		for(int i=1;i<=n;i++)
		//if(! h[i])
		{
			memset(u,0,sizeof(u));
			if(!dfs(i))
			{
				flag=0;
				break;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
