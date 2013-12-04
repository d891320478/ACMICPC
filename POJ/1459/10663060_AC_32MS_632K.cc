#include <cstdio>
#include <cstring>
#define N 210
#define M 40010
#define INF 1<<30
struct Edge
{
	int v,next,w;
}e[M];
int head[N],cnt;
int n,m;
int s,t;
int pre[N],cur[N],dis[N],gap[N];
void addedge(int u,int v,int w)
{
	e[cnt].v=v; e[cnt].w=w; e[cnt].next=head[u]; head[u]=cnt++;
	e[cnt].v=u; e[cnt].w=0; e[cnt].next=head[v]; head[v]=cnt++;
}
int sap(int n)
{
	int i,v,u,flow=0,aug=INF;
	int flag;
	for(i=1;i<=n;i++)
	{
		gap[i]=dis[i]=0;
		cur[i]=head[i];
	}
	gap[0]=n;
	u=pre[s]=s;
	while (dis[s]<n)
	{
		flag=0;
		for(int j=cur[u];j!=-1;j=e[j].next)
		{
			v=e[j].v;
			if(e[j].w>0 && dis[u]==dis[v]+1)
			{
				flag=1;
				if(e[j].w<aug)aug=e[j].w;
				pre[v]=u;
				u=v;
				if(u==t)
				{
					flow+=aug;
					while (u!=s)
					{
						u=pre[u];
						e[cur[u]].w-=aug;
						e[cur[u]^1].w+=aug;
					}
					aug=INF;
				}
				break;
			}
			cur[u]=e[j].next;
		}
		if(flag)continue;
		int mindis=n;
		for(int j=head[u];j!=-1;j=e[j].next)
		{
			v=e[j].v;
			if(e[j].w>0 && mindis>dis[v])
			{
				mindis=dis[v];
				cur[u]=j;
			}
		}
		if(--gap[dis[u]]==0)break;
		dis[u]=mindis+1;
		++gap[dis[u]];
		u=pre[u];
	}
	return flow;
}
int main ()
{
	int n1,n2;
	while (scanf("%d%d%d%d",&n,&n1,&n2,&m)!=-1)
	{
		s=n+1;t=n+2;
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			int u,v,w;
			scanf(" (%d,%d)%d",&u,&v,&w);
			u++,v++;
			addedge(u,v,w);
		}
		while (n1--)
		{
			int u,w;
			scanf(" (%d)%d",&u,&w);
			u++;
			addedge(s,u,w);
		}
		while (n2--)
		{
			int u,w;
			scanf(" (%d)%d",&u,&w);
			u++;
			addedge(u,t,w);
		}
		printf("%d\n",sap(n+2));
	}
	
	return 0;
}