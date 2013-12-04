#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 510
#define M 2010
int d[N],head[N],next[M],e[M],l[M],a;
int n,m,c,t;
int i,j,k;
int vis[N],ans[N];
queue<int>q;
int main()
{
	while (scanf("%d%d%d%d",&n,&m,&c,&t)!=-1)
	{
		memset(d,0x5f,sizeof(d));
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		for(i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			next[i*2]=head[u];
			e[i*2]=v;
			l[i*2]=w;
			head[u]=i*2;
			next[i*2+1]=head[v];
			e[i*2+1]=u;
			l[i*2+1]=w;
			head[v]=i*2+1;
		}
		vis[1]=1;
		q.push(1);
		d[1]=0;
		while (! q.empty())
		{
			int x=q.front();
			q.pop();
			vis[x]=0;
			for(i=head[x];i!=-1;i=next[i])
			if(d[e[i]]>d[x]+l[i])
			{
				d[e[i]]=d[x]+l[i];
				if(! vis[e[i]])
				{
					vis[e[i]]=1;
					q.push(e[i]);
				}
			}
		}
		ans[0]=0;
		for(i=1;i<=c;i++)
		{
			scanf("%d",&a);
			if(d[a]<=t)ans[++ans[0]]=i;
		}
		for(i=0;i<=ans[0];i++)
			printf("%d\n",ans[i]);
	}
	
	return 0;
}