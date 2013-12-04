#include<stdio.h>
#include<string.h>
const int N=20010;
const int M=800010;
const int inf=1<<30;
struct Edge
{    int v,next,w;	}e[M];
int head[N],cnt;	int n,m,ans;	int s,t;	int pre[N],cur[N],dis[N],gap[N];
int q[N],open,tail;
void addedge(int u,int v,int w)
{
    e[cnt].v=v;    e[cnt].w=w;    e[cnt].next=head[u];    head[u]=cnt++;
    e[cnt].v=u;    e[cnt].w=0;    e[cnt].next=head[v];    head[v]=cnt++;
}
void BFS()
{
	int i,u,v;
	memset(gap,0,sizeof(gap));
	memset(dis,-1,sizeof(dis));
	open=tail=0;
	q[open]=t;
	dis[t]=0;
	while (open<=tail)
	{
		u=q[open++];
		for(i=head[u];i!=-1;i=e[i].next)
		{
			v=e[i].v;
			if(e[i].w!=0 || dis[v]!=-1) continue;
			q[++tail]=v;
			++gap[dis[v]=dis[u]+1];
		}
	}
}
int sap(int n)
{
    int i,v,u,flow=0,aug=inf;
    int flag;
    BFS();
    gap[0]=1;
    for (i=1;i<=n;i++) cur[i]=head[i];
    u=pre[s]=s;
	while (dis[s]<n)
	{   flag=0;
        for (int j=cur[u];j!=-1;j=e[j].next)
	 {   v=e[j].v;
            if (e[j].w>0&&dis[u]==dis[v]+1)
		   {
                flag=1;    if (e[j].w<aug) aug=e[j].w;     pre[v]=u;      u=v;
                if (u==t)
			   {
                    flow+=aug;
                    while (u!=s)
				   {  u=pre[u];   e[cur[u]].w-=aug;    e[cur[u]^1].w+=aug;    }
                    aug=inf;
                }
                break;
            }
            cur[u]=e[j].next;
        }
        if (flag) continue;
        int mindis=n;
        for (int j=head[u];j!=-1;j=e[j].next)
	    {
            v=e[j].v;
            if (e[j].w>0&&mindis>dis[v])
		   {   mindis=dis[v];    cur[u]=j;	}
        }
        if (--gap[dis[u]]==0) break;
	    ++gap[dis[u]=mindis+1];     u=pre[u];
    }
   return flow;
}
int main()
{
    int i;
    while(scanf("%d%d",&n,&m)!=-1)
    {
		memset(head,-1,sizeof(head));
		s=n+1;
		t=s+1;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			addedge(s,i,a);
			addedge(i,t,b);
		}
		while (m--)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		n+=2;
		printf("%d\n",sap(n));
	}
	return 0;
}