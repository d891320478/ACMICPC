#include <cstdio>
#include <cstring>
int x[]={-1,0,1,0},y[]={0,1,0,-1};
int n,m,kk;
int g[1100][1100],u[1100],h[1100],q[1100],va;
bool a[35][35];
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
	while(scanf("%d%d%d",&n,&m,&kk)!=EOF)
	{
		va=0;
		memset(u,0,sizeof(u));	memset(h,0,sizeof(h));	memset(q,0,sizeof(q));
		memset(a,0,sizeof(a));
		for(int i=1;i<=kk;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y]=1;
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(! a[i][j])
		if(i%2==j%2)
		{
			int ue=(i-1)*n+j,ve;
			for(int k=0;k<4;k++)
			if(i+x[k]>0 && i+x[k]<=n)
			if(j+y[k]>0 && j+y[k]<=m)
			if(! a[i+x[k]][j+y[k]])
			{
				ve=(i+x[k]-1)*n+j+y[k];
				g[ue][++g[ue][0]]=ve;
				if(! h[ue])
				if(! u[ve])	
				{
				    va++;
				    h[ue]=ve;
				    q[ve]=ue;
				    u[ve]=1;
				}
			}
		}
		n=m*n;
		for(int i=1;i<=n;i++)
		if(! h[i])
		{
			memset(u,0,sizeof(u));
			if(dfs(i))va++;
		}
		if(va*2==n-kk)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}