#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 20010
#define INF (1<<30)
int head[N],next[N<<1],e[N<<1],cnt;
int n,ans,mn,sz[N];
void add(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
void dfs(int u,int f)
{
	int sum=0;
	sz[u]=0;
	for(int i=head[u];i!=-1;i=next[i])
	if(e[i]!=f)
	{
		dfs(e[i],u);
		sz[u]+=sz[e[i]]+1;
		sum=max(sum,sz[e[i]]+1);
	}
	sum=max(sum,n-1-sz[u]);
	if(sum==mn) ans=min(ans,u);
	else if(sum<mn)
	{
		mn=sum;
		ans=u;
	}
}
int main ()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		scanf("%d",&n);
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		mn=ans=INF;
		dfs(1,0);
		printf("%d %d\n",ans,mn);
	}
	return 0;
}