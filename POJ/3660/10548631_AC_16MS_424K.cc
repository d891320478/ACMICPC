#include <cstdio>
#include <cstring>
#define N 110
#define M 4510
int head[N],next[M],e[M];
int n,m;
int into[N],out[N];
bool vis[N];
void dfs(int s,int start)
{
	vis[s]=1;
	for(int i=head[s];i!=-1;i=next[i])
	if(! vis[e[i]])
	{
		out[start]++;
		vis[e[i]]=1;
		into[e[i]]++;
		dfs(e[i],start);
	}
}
int main ()
{
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++)
	{
		int ue,ve;
		scanf("%d%d",&ue,&ve);
		next[i]=head[ue];
		head[ue]=i;
		e[i]=ve;
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(i,i);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
		if(into[i]+out[i]==n-1)sum++;
	printf("%d\n",sum);
	return 0;
}