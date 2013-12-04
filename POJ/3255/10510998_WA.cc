#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 5010
#define M 200010
int ds[N],dt[N],head[N],next[M],e[M],l[M];
int n,m,cnt;
void spfa(int s,int *d)
{
	int vis[N]={0};
	queue<int>q;
	q.push(s);
	vis[s]=1;
	while (! q.empty())
	{
		int now=q.front();
		q.pop();
		vis[now]=0;
		for(int i=head[now];i!=-1;i=next[i])
			if(d[e[i]]==0 || d[e[i]]>d[now]+l[i])
			{
				d[e[i]]=d[now]+l[i];
				if(! vis[e[i]])
				{
					vis[e[i]]=1;
					q.push(e[i]);
				}
			}
	}
}
int main ()
{
	int i,j,ans=-1;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	while (m--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		next[cnt]=head[u];
		e[cnt]=v;
		l[cnt]=w;
		head[u]=cnt++;
		next[cnt]=head[v];
		e[cnt]=u;
		l[cnt]=w;
		head[v]=cnt++;
	}
	spfa(1,ds);
	spfa(n,dt);
	for(i=1;i<=n;i++)
	for(j=head[i];j!=-1;j=next[j])
		if(ds[i]+dt[e[j]]+l[j]>ds[n])
		if(ans==-1 || ds[i]+dt[e[j]]+l[j]<ans)
			ans=ds[i]+dt[e[j]]+l[j];
	printf("%d\n",ans);
	
	return 0;
}