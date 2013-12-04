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
#define N 1010
#define M 2000010
int n,m;
int cnt,head[N];
int dfn[N],low[N],stack[M],step,color[N],top;
struct edge
{
	int v,next;
}e[M];
void addedge(int u,int v)
{
	e[cnt].next=head[u];
	e[cnt].v=v;
	head[u]=cnt++;
}
bool g[N][N],odd[N],mark[N];
bool colored(int s,int c)
{
	color[s]=c;
	for(int i=head[s];i!=-1;i=e[i].next)
	if(mark[e[i].v])
	{
		if(! color[e[i].v])
		{
			if(! colored(e[i].v,-c)) return 0;
		}
		else if(color[e[i].v]==color[s]) return 0;
	}
	return 1;
}
void check(int l,int r)
{
	memset(mark,0,sizeof(mark));
	memset(color,0,sizeof(color));
	for(int j=l;j<r;j++)
	{
		int i=stack[j];
		mark[e[i].v]=mark[e[i^1].v]=1;
	}
	if(! colored(e[stack[l]].v,1))
		for(int j=1;j<=n;j++)
			if(mark[j]) odd[j]=1;
}
void dfs(int s,int fa)
{
	int now;
	dfn[s]=low[s]=++step;
	for(int i=head[s];i!=-1;i=e[i].next)
	if(e[i].v!=fa)
	{
		now=top;
		stack[top++]=i;
		if(! dfn[e[i].v])
		{
			dfs(e[i].v,s);
			low[s]=min(low[s],low[e[i].v]);
			if(low[e[i].v]>=dfn[s])
			{
				check(now,top);
				top=now;
			}
		}
		else low[s]=min(dfn[e[i].v],low[s]);
	}
}
int main ()
{
	int i,j;
	while (scanf("%d%d",&n,&m) && n+m!=0)
	{
		memset(head,-1,sizeof(head));
		memset(dfn,0,sizeof(dfn));
		top=cnt=step=0;
		memset(g,0,sizeof(g));
		while (m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u][v]=g[v][u]=1;
		}
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(! g[i][j]) {addedge(i,j);addedge(j,i);}
		memset(odd,0,sizeof(odd));
		for(i=1;i<=n;i++)
			if(! dfn[i]) dfs(i,-1);
		int ans=0;
		for(i=1;i<=n;i++)
			ans+=odd[i];
		printf("%d\n",n-ans);
	}
	
	return 0;
}