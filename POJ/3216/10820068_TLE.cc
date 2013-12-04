#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 30
#define M 10010
int n,m;
int a[N][N];
int head[N],next[M],e[M],cnt,h[N],q[N],vis[N];
void addedge(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
int dfs(int s)
{
	for(int i=head[s];i!=-1;i=next[i])
	{
		int v=e[i];
		if(! vis[v])
		{
			vis[v]=1;
			if(q[v]==0 || dfs(q[v]))
			{
				h[s]=v;
				q[v]=s;
				return 1;
			}
		}
	}
	return 0;
}
int u[N],v[N],w[N];
int main ()
{
	int i,j,k;
	while (scanf("%d%d",&n,&m) && n+m)
	{
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
		for(i=1;i<=m;i++)
			scanf("%d%d%d",&u[i],&v[i],&w[i]);
		for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][k]>=0 && a[k][j]>=0)
			if(a[i][j]==-1 || a[i][j]>a[i][k]+a[k][j])
				a[i][j]=a[i][k]+a[k][j];
		cnt=0;
		SET(head,-1);
		for(i=1;i<=m;i++)
		for(j=1;j<=m;j++)
			if(i!=j)
			if(a[u[i]][u[j]]>=0)
			if(v[i]+w[i]+a[u[i]][u[j]]<=v[j])
				addedge(i,j);
		int va=0;
		memset(q,0,sizeof(q));
		memset(h,0,sizeof(h));
		for(i=1;i<=m;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) va++;
		}
		printf("%d\n",m-va);
	}
	
	return 0;
}