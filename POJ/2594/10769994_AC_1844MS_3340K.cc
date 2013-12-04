#include <cstdio>
#include <cstring>
#define N 510
#define M 250010
int n,m,p,ans;
int head[N],next[M],e[M],u[N],h[N],q[N],va,cnt;
int dfs(int i)
{
    for(int j=head[i];j!=-1;j=next[j])
  		if(! u[e[j]])
  		{	u[e[j]]=1;
   			if( q[e[j]]==0 || dfs(q[e[j]]) )
   			{    	q[e[j]]=i;		h[i]=e[j];		return 1;		}
  		}
    return 0;
}
int main()
{

	int a[N][N],i,j,k,into[N],out[N];
	while(scanf("%d%d",&n,&m) && (n || m))
	{
		memset(h,0,sizeof(h));	memset(q,0,sizeof(q));	memset(head,-1,sizeof(head));
		memset(e,0,sizeof(e));	memset(next,0,sizeof(next));
		memset(into,0,sizeof(into));
		memset(out,0,sizeof(out));
		cnt=0;
		memset(a,0,sizeof(a));
		ans=va=0;
		while (m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			a[u][v]=1;
		}
		for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[i][j]=a[i][k] && a[k][j] || a[i][j];
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j && a[i][j])
			{
				next[cnt]=head[i];
				e[cnt]=j;
				head[i]=cnt++;
			}
		for(i=1;i<=n;i++)
			{
				memset(u,0,sizeof(u));
				if(dfs(i)) va++;
			}
		printf("%d\n",n-va);
		/*for(i=1;i<=n;i++)
			printf("%d %d\n",h[i],q[i]);
		printf("\n");*/
	}
	return 0;
}