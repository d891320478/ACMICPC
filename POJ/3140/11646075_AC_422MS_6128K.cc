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
#define N 100010
#define M 200010
#define ABS(x) ((x)>0?(x):(-(x)))
long long n,m;
long long head[N],next[M],e[M],cnt;
long long val[N],dis[N];
long long ans;
void add(long long u,long long v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
void dfs1(long long u,long long f)
{
	dis[u]=val[u];
	for(long long i=head[u];i!=-1;i=next[i])
	if(e[i]!=f)
	{
		dfs1(e[i],u);
		dis[u]+=dis[e[i]];
	}
}
void dfs2(long long u,long long f)
{
	for(long long i=head[u];i!=-1;i=next[i])
	if(e[i]!=f)
	{
		if(ans==-1 || ans>ABS(dis[e[i]]-(dis[1]-dis[e[i]])))
			ans=ABS(dis[e[i]]-(dis[1]-dis[e[i]]));
		dfs2(e[i],u);
	}
}
int main()
{
	int tt=0;
	while (scanf("%lld%lld",&n,&m) && n+m)
	{
		for(long long i=1;i<=n;i++) scanf("%lld",&val[i]);
		m=n-1;
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			long long u,v;
			scanf("%lld%lld",&u,&v);
			add(u,v);
			add(v,u);
		}
		memset(dis,0,sizeof(dis));
		dfs1(1LL,-1LL);
		ans=-1LL;
		dfs2(1LL,-1LL);
		printf("Case %d: %lld\n",++tt,ans);
	}
	return 0;
}