#include <cstdio>
#include <cstring>
#define N 510
#define M 80000
#define INF 1<<30
struct Edge
{
	int v,w,next;
}e[M];
int head[N],cnt,n,m,ans,s,t,pre[N],dis[N],cur[N],gap[N];
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
					while(u!=s)
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
		++gap[dis[u]=mindis+1];
		u=pre[u];
	}
	return flow;
}
int main ()
{
	int g[N][N],i,j,k,p=1;
	scanf("%d%d%d",&n,&s,&t);
	cnt=0;
	memset(head,-1,sizeof(head));
	s+=n;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&g[i][j]);
		if(i==j)addedge(i,i+n,1);
		else if(g[i][j])
			addedge(i+n,j,100000);
	}
	if(g[s-n][t]==1)
	{
		printf("NO ANSWER!\n");
		return 0;
	}
	ans=sap(n*2);
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
	if(i!=s-n && i!=t)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		for(j=1;j<=n;j++)
			if(j!=i) addedge(j,j+n,1);
		for(j=1;j<=n;j++)
		for(k=1;k<=n;k++)
			if(j!=k)
				if(g[j][k])
					addedge(j+n,k,100000);
		if(sap(n*2)<ans)
		{
			ans--;
			if(p){p=0;printf("%d",i);}
			else printf(" %d",i);
			for(j=1;j<=n;j++)
				g[i][j]=g[j][i]=0;
		}
	}
	printf("\n");
	return 0;
}