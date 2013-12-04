#include<stdio.h>
#include<string.h>
const int N=1100;
const int M=50000;
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

	int a[1010][30],i,j,k,l,r,mid,z[30];
	scanf("%d%d",&n,&m);
	s=n+m+1,t=s+1;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		scanf("%d",&a[i][j]);
	for(j=1;j<=m;j++) scanf("%d",&z[j]);
	ans=inf;
	for(i=1;i<=m;i++)
	{
		//printf("%d   ",i);
		l=0; r=i;
		while (l<r)
		{
			mid=(l+r)/2;
			cnt=0;
			memset(head,-1,sizeof(head));
			for(j=1;j<=n;j++) addedge(s,j,1);
			for(j=1;j<=m;j++) addedge(j+n,t,z[j]);
			for(j=1;j<=n;j++)
			for(k=i-mid;k<=i;k++)
				addedge(j,a[j][k]+n,1);
			int sapp=sap(n+m+2);
			//printf("l= %d r= %d mid= %d sapp= %d   ",l,r,mid,sapp);
			if(sapp==n) r=mid;
			else l=mid+1;
		}
		if(l<i) ans=ans<l?ans:l;
		//printf("l = %d\n",l);
		//printf("\n");
	}
	printf("%d\n",ans+1);
	return 0;
}