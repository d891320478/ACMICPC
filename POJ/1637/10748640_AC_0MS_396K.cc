#include<stdio.h>
#include<string.h>
const int N=300;
const int M=40000;
const int inf=1<<30;
struct Edge
{    int v,next,w;	}e[M];
int head[N],cnt;	int n,m,ans;	int s,t;	int pre[N],cur[N],dis[N],gap[N];
void addedge(int u,int v,int w)
{
    e[cnt].v=v;    e[cnt].w=w;    e[cnt].next=head[u];    head[u]=cnt++;
    e[cnt].v=u;    e[cnt].w=0;    e[cnt].next=head[v];    head[v]=cnt++;
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
int main()
{
	int tttt,anss,into[N],i;
	scanf("%d",&tttt);
	while (tttt--)
	{
		anss=0;
		scanf("%d%d",&n,&m);
		memset(head,-1,sizeof(head));
		memset(into,0,sizeof(into));
		cnt=0;
		while (m--)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if(w==1) into[u]++,into[v]--;
			else
			{
				addedge(u,v,1);
				into[u]++,into[v]--;
			}
		}
		s=n+1,t=n+2;
		for(i=1;i<=n;i++)
			if(into[i]%2!=0)break;
			else if(into[i]>0) {addedge(s,i,into[i]/2);anss+=into[i]/2;}
				 else if(into[i]<0) addedge(i,t,-into[i]/2);
		if(i<=n)
		{
			printf("impossible\n");
			continue;
		}
		ans=sap(n+2);
		if(ans==anss)printf("possible\n");
		else printf("impossible\n");
	}
	return 0;
}