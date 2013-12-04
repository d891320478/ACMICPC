#include <cstdio>
#include <cstring>
int n,m;			int g[210][210],u[210],h[210],q[210],va;
int dfs(int i)
{
    for(int j=1;j<=g[i][0];j++)
  	if(! u[g[i][j]])
  	{
   		u[g[i][j]]=1;
   		if( (q[g[i][j]]==-1) || (dfs(q[g[i][j]])) )
   		{	q[g[i][j]]=i;	h[i]=g[i][j];	return 1;		}
  	}
    return 0;
}
char a[12][12],ch;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%c",&n,&m,&ch);
		for(int i=0;i<n;i++)
			scanf("%s",a[i]);
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
		for(int j=i%2;j<m;j+=2)
			if(a[i][j]=='*')
			{
				int u=i*m+j,v;
				if(i-1>=0 && a[i-1][j]=='*')
				{
					v=(i-1)*m+j;
					g[u][++g[u][0]]=v;
				}
				if(i+1<n && a[i+1][j]=='*')
				{
					v=(i+1)*m+j;
					g[u][++g[u][0]]=v;
				}
				if(j-1>=0 && a[i][j-1]=='*')
				{
					v=u-1;
					g[u][++g[u][0]]=v;
				}
				if(j+1<m && a[i][j+1]=='*')
				{
					v=u+1;
					g[u][++g[u][0]]=v;
				}
			}
		va=0;
		memset(u,0,sizeof(u));
		memset(h,-1,sizeof(h));
		memset(q,-1,sizeof(q));
		for(int i=0;i<n*m;i++)
		{
			if(h[i]==-1)
			for(int j=1;j<=g[i][0];j++)
				if(! u[g[i][j]])	
				{
					va++;
					h[i]=g[i][j];
					q[g[i][j]]=i;
					u[g[i][j]]=1;
					break;
				}
		}
		for(int i=0;i<n*m;i++)
		if(h[i]==-1)
		{	memset(u,0,sizeof(u));	if(dfs(i))va++;	}
		for(int i=0;i<n;i++)
		for(int j=i%2;j<m;j+=2)
			if(a[i][j]=='*' && h[i*m+j]==-1)va++;
		for(int i=0;i<n;i++)
		for(int j=1-i%2;j<m;j+=2)
			if(a[i][j]=='*' && q[i*m+j]==-1)va++;
		printf("%d\n",va);
	}
	return 0;
}
