#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
#include<vector>
#include<utility>
using namespace std;
#define N 210
#define INF (1<<30)
int c[N][N],f[N][N],pre[N],vis[N],d[N];
int q[N],open,tail;
int maxflow(int n,int s,int t)
{
	int i,j,u,v,flow=0;
	memset(f,0,sizeof(f));
	do{
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		q[open=tail=0]=s;
		vis[s]=1;
		d[s]=INF;
		for(;open<=tail && !vis[t];)
		for(u=q[open++],v=1;v<=n;v++)
		if(! vis[v] && f[u][v]<c[u][v])
		{
			vis[v]=1;
			q[++tail]=v;
			pre[v]=u;
			if(d[u]<c[u][v]-f[u][v]) d[v]=d[u];
			else d[v]=c[u][v]-f[u][v];
		}
		if(! vis[t]) break;
		flow+=d[t];
		for(u=t;u!=s;)
		{
			v=u;
			u=pre[v];
			f[u][v]+=d[t];
			f[v][u]=-f[u][v];
		}
	} while (d[t]>0);
	return flow;
}
int n,m;
int main()
{
	scanf("%d%d",&m,&n);
	while (m--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		c[u][v]+=w;
	}
	printf("%d\n",maxflow(n,1,n));
	return 0;
}