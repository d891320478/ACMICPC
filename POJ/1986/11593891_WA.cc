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
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 100010
#define M 20
int dis[N],dep[N],pnt[N][M],pre[N];	int p[M];	int n,root,m;
int head[N],e[N*2],w[N*2],next[N*2],cnt;
void addedge(int u,int v,int val)
{	next[cnt]=head[u];	e[cnt]=v;	w[cnt]=val;	head[u]=cnt++;	}
void init(){	for(int i=0;i<M;i++) p[i]=1<<i;	}
void dfs(int u,int d,int f)
{	dep[u]=d; pre[u]=f;
	for(int i=head[u];i!=-1;i=next[i])	if(e[i]!=f)
	{	dis[e[i]]=dis[u]+w[i];	dfs(e[i],d+1,u);	}
}
void make_pnt()
{	memset(pnt,-1,sizeof(pnt));
	for(int i=1;i<=n;i++) pnt[i][0]=pre[i];
	for(int j=1;p[j]<n;j++)
	for(int i=1;i<=n;i++)	if(pnt[i][j-1]!=-1)	pnt[i][j]=pnt[pnt[i][j-1]][j-1];
}
int lca(int x,int y)
{	int log=0;
	if(dep[x]<dep[y]) swap(x,y);
	while (p[log+1]<=dep[x]) log++;
	for(int i=log;i>=0;i--)	if(dep[x]-p[i]>=dep[y]) x=pnt[x][i];
	if(x==y) return x;
	for(int i=log;i>=0;i--) if(pnt[x][i]!=-1 && pnt[x][i]!=pnt[y][i]) x=pnt[x][i],y=pnt[y][i];
	return pre[x];
}
int fastget()
{
	char c; int ans=0; c=getchar();
	int sign=1;
	while (! (c>='0' && c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while (c>='0' && c<='9')
	{
		ans=(ans<<3)+(ans<<1)+c-'0';
		c=getchar();
	}
	return ans*sign;
}
int main()
{	init();
	{	n=fastget();
		m=fastget();
		memset(pre,0,sizeof(pre));	memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=1;i<n;i++)
		{	int u=fastget(),v=fastget(),w=fastget();
			addedge(u,v,w);	addedge(v,u,w);
		}
		root=1;
		dis[root]=0;	dfs(root,0,0);	make_pnt();	int x,y;
		int tt=fastget();
		while (tt--)
		{
			x=fastget();
			y=fastget();
			printf("%d\n",dis[x]+dis[y]-dis[lca(x,y)]);
		}
	}
	return 0;
}