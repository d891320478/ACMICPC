#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 110
#define M 20010
#define INF 2100000000
int head[N],cnt;
struct edge
{
	int v,w,next,c;
}e[M];
int co,n,m,d[N][M],vis[N][M];
struct fff
{
	int p,s;
}aaa;
queue<fff>q;
void addedge(int u,int v,int w,int c)
{
	e[cnt].next=head[u];
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].c=c;
	head[u]=cnt++;
}
int main ()
{
	while(scanf("%d%d%d",&co,&n,&m)!=-1)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			int u,v,w,c;
			scanf("%d%d%d%d",&u,&v,&w,&c);
			addedge(u,v,w,c);
		}
		memset(d,-1,sizeof(d));
		vis[1][co]=1;
		d[1][co]=0;
		q.push((fff){1,co});
		while(! q.empty())
		{
			aaa=q.front();
			q.pop();
			int u=aaa.p,cost=aaa.s;
			vis[u][cost]=0;
			for(int i=head[u];i!=-1;i=e[i].next)
				if(cost-e[i].c>=0)
				if(d[e[i].v][cost-e[i].c]==-1 || d[e[i].v][cost-e[i].c]>d[u][cost]+e[i].w)
				{
					d[e[i].v][cost-e[i].c]=d[u][cost]+e[i].w;
					if(! vis[e[i].v][cost-e[i].c])
					{
						vis[e[i].v][cost-e[i].c]=1;
						q.push((fff){e[i].v,cost-e[i].c});
					}
				}
		}
		int ans=INF;
		for(int i=0;i<=co;i++)
			if(d[n][i]>=0) ans=min(ans,d[n][i]);
		if( ans!=INF )printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}