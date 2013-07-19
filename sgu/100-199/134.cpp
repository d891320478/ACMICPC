#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 16010
#define INF (1<<30)
int head[N],next[N<<1],e[N<<1],cnt;
int n,ans[N],mn,sz[N];
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
	if(sum==mn) ans[++ans[0]]=u;
	else if(sum<mn)
	{
		mn=sum;
		ans[0]=1;
		ans[1]=u;
	}
}
int main ()
{
freopen("1.in","r",stdin);
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
	mn=INF;
	dfs(1,0);
	sort(ans+1,ans+1+ans[0]);
	printf("%d %d\n",mn,ans[0]);
	for(int i=1;i<=ans[0];++i)
	{
		printf("%d",ans[i]);
		if(i<ans[0]) printf(" ");
		else printf("\n");
	}
	return 0;
}
