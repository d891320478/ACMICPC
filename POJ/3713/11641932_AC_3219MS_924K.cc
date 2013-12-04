#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
#define N 510
#define M 40010
int head[N],next[M],e[M],cnt;
int dfn[N],low[N],vis[N],step;
int n,m,fl;
void add(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
int bfs()
{
	queue<int> q;
	memset(vis,0,sizeof(vis));
	q.push(0);
	vis[0]=1;
	int sum=1;
	while (! q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i!=-1;i=next[i])
		if(! vis[e[i]])
		{	
			sum++;
			vis[e[i]]=1;
			q.push(e[i]);
		}
	}
	return sum==n;
}
void dfs(int u,int f)
{
	int flag=0,s=0,v;
	dfn[u]=low[u]=++step;
	//printf("u = %d\n",u);
	for(int i=head[u];i!=-1;i=next[i])
	if(! vis[e[i]])
	if(e[i]!=f)
	{
		v=e[i];
		//printf(" v = %d\n",v);
		if(! dfn[v])
		{
			s++;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]) flag=1;
		}
		else low[u]=min(low[u],dfn[v]);
	}
	if((f==-1 && s>1) || (f>=0 && flag)) fl=0;
}
int main ()
{
	while (scanf("%d%d",&n,&m) && n+m)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v); add(v,u);
		}
		if(! bfs())
		{
			printf("NO\n");
			continue;
		}		
		memset(vis,0,sizeof(vis));
		fl=1;
		for(int i=0;fl && i<n;i++)
		{
			vis[i]=1;
			memset(dfn,0,sizeof(dfn));
			step=0;
			if(i==0) dfs(1,-1);
			else dfs(0,-1);
			vis[i]=0;
			//printf("i = %d\n",i);
		}
		if(! fl) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}