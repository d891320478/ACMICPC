#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 4010
#define M 300010
int head[N],cnt,e[M],next[M];
int n,a[N];
int color,step,dfn[N],low[N],vis[N],ins[N];
stack<int> q;
void addedge(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
void dfs(int u)
{
	dfn[u]=low[u]=++step;
	q.push(u);
	ins[u]=1;
	for(int i=head[u];i!=-1;i=next[i])
	{
		if(! dfn[e[i]])
		{
			dfs(e[i]);
			low[u]=min(low[u],low[e[i]]);
		}
		else if(ins[e[i]]) low[u]=min(low[u],dfn[e[i]]);
	}
	if(dfn[u]==low[u])
	{
		color++;
		int j;
		do{
			j=q.top(); q.pop(); ins[j]=0; vis[j]=color;
		} while (j!=u);
	}
}
int main ()
{
	scanf("%d",&n);
	cnt=0;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
	{
		int k,j;
		scanf("%d",&k);
		while (k--)
		{
			scanf("%d",&j);
			addedge(i,j+n);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		addedge(k+n,i);
	}
	color=step=0;
	for(int i=1;i<=n*2;i++)
		if(! dfn[i]) dfs(i);
	for(int i=1;i<=n;i++)
	{
		a[0]=0;
		for(int j=n+1;j<=n+n;j++)
			if(vis[i]==vis[j]) a[++a[0]]=j-n;
		for(int j=0;j<=a[0];j++)
		{
			printf("%d",a[j]);
			if(j<a[0]) printf(" ");
			else printf("\n");
		}
	}
	
	return 0;
}