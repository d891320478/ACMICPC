#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
const int N=200;
const int M=40000;
const int inf=1<<30;
struct Edge
{    int v,next,w;	}e[M];
int head[N],cnt;	int n,m,ans;	int s,t;	int pre[N],cur[N],dis[N],gap[N];
bool vis[N];
struct ad
{
	int x;
	char y;
}ais[N];
void addedge(int u,int v,int w)
{
    e[cnt].v=v;    e[cnt].w=w;    e[cnt].next=head[u];    head[u]=cnt++;
    e[cnt].v=u;    e[cnt].w=0;    e[cnt].next=head[v];    head[v]=cnt++;
}
int cmp(const ad &a,const ad &b)
{
	return a.x<b.x;
}
int sap(int n)
{
    int i,v,u,flow=0,aug=inf;
    int flag;
    for (i=1;i<=n;i++)
    {   gap[i]=dis[i]=0;       cur[i]=head[i];    }
    gap[0]=n; //gap[s]=n;
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
        dis[u]=mindis+1;   ++gap[dis[u]];     u=pre[u];
    }
   return flow;
}
void dfs(int s)
{
	vis[s]=1;
	for(int i=head[s];i!=-1;i=e[i].next)
		if(e[i].w>0 && ! vis[e[i].v]) dfs(e[i].v);
}
int main()
{

	int i,j,w,u,v;
	scanf("%d%d",&n,&m);
	s=2*n+1,t=s+1;
	cnt=0;
	memset(head,-1,sizeof(head));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		addedge(s,i,w);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		addedge(i+n,t,w);
	}
	while (m--)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v+n,100000000);
	}
	ans=sap(t);
	printf("%d\n",ans);
	dfs(s);
	int diy=0;
	for(j=head[s];j!=-1;j=e[j].next)
		if(! vis[e[j].v])
		{
			diy++;
			ais[diy].x=e[j].v;
			ais[diy].y='-';
		}
	/*for(i=1;i<=t;i++)
		printf("%d ",vis[i]);
	printf("\n");*/
	for(i=n+1;i<s;i++)
		if(vis[i])
		{
			diy++;
			ais[diy].x=i-n;
			ais[diy].y='+';
		}
	printf("%d\n",diy);
	for(i=1;i<=diy;i++)
		printf("%d %c\n",ais[i].x,ais[i].y);
		
	return 0;
}