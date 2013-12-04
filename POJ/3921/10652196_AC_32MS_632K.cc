#include<stdio.h>
#include<string.h>
const int N=200;
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
int a[N][N],kk,ue[M],ve[M];
int main()
{
	//freopen("1.in","r",stdin);
	int i,j,k,mm;
	while (scanf("%d%d%d",&n,&m,&kk))
	{
		if(!(n || m || kk))break;
		memset(a,0x1f,sizeof(a));
		mm=0;
		for ( i = 0; i < m; i += 1)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(a[u][v]!=1)
			{
				a[u][v]=1;
				ue[mm]=u;
				ve[mm]=v;
				mm++;
			}
		}
		for(i=1;i<=n;i++)
			a[i][i]=0;
		for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]>a[i][k]+a[k][j])	a[i][j]=a[i][k]+a[k][j];
		s=n+1; t=n;
		cnt=0;
		memset(head,-1,sizeof(head));
		for(j=1;j<=n;j++)
			addedge(j,j+n,1);
		for(j=0;j<mm;j++)
			if (a[1][ue[j]]+a[ve[j]][n]<kk)
				addedge(ue[j]+n,ve[j],inf);
		int ans=sap(n*2);
		printf("%d\n",ans);
	}
	return 0;
}