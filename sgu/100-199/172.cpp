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
#define NN 210
#define MM 60010
int head[NN],next[MM],e[MM],cnt;
int n,m;
int vis[NN],flag;
void add(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
void dfs(int u,int col)
{
	if(! flag) return;
	vis[u]=col;
	for(int i=head[u];i!=-1;i=next[i])
	{
		if(vis[e[i]]==vis[u])
		{
			flag=0;
			return;
		}
		if(vis[e[i]]==-1) dfs(e[i],1-col);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	cnt=0;
	memset(head,-1,sizeof(head));
	memset(vis,-1,sizeof(vis));
	while (m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	flag=1;
	for(int i=1;flag && i<=n;i++)
		if(vis[i]==-1) dfs(i,1);
	if(! flag) printf("no");
	else
	{
		printf("yes\n");
		int ans=0;
		for(int i=1;i<=n;i++) ans+=vis[i];
		printf("%d\n",ans);
		flag=0;
		for(int i=1;i<=n;i++)
		if(vis[i])
		{
			ans--;
			printf("%d",i);
			if(ans) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
