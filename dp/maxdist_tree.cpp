//树上每个点的最远距离
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
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 20010
int head[N],cnt,n;
int ans[N];
struct edge
{
	int v,w,next,dis;
}e[M];
void add(int u,int v,int w)
{
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].dis=w;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
int dfs1(int u,int f)
{
	int mx=0;
	for(int i=head[u];i!=-1;i=e[i].next)
	if(e[i].v!=f)
	{
		e[i].dis=dfs1(e[i].v,u)+e[i].w;
		mx=max(e[i].dis,mx);
	}
	return mx;
}
void dfs2(int u,int f)
{
	ans[u]=0;
	for(int i=head[u];i!=-1;i=e[i].next)
	{
		if(e[i].v==f)
		{
			for(int j=head[f];j!=-1;j=e[j].next)
			if(e[j].v!=u)
				e[i].dis=max(e[i].dis,e[i].w+e[j].dis);
		}
		ans[u]=max(ans[u],e[i].dis);
	}
	for(int i=head[u];i!=-1;i=e[i].next)
		if(e[i].v!=f) dfs2(e[i].v,u);
}
int main()
{
	cnt=0;
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int u,w;
		scanf("%d%d",&u,&w);
		add(u,i,w);
		add(i,u,w);
	}
	dfs1(1,-1);
	dfs2(1,-1);
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}
