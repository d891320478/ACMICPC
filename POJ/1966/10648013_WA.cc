#include<stdio.h>
#include<string.h>
const long long N=200;
const long long M=40000;
const long long inf=1<<30;
struct Edge
{    long long v,next,w;	}e[M];
long long head[N],cnt;	long long n,m,ans;	long long s,t;	long long pre[N],cur[N],dis[N],gap[N];
void addedge(long long u,long long v,long long w)
{
    e[cnt].v=v;    e[cnt].w=w;    e[cnt].next=head[u];    head[u]=cnt++;
    e[cnt].v=u;    e[cnt].w=0;    e[cnt].next=head[v];    head[v]=cnt++;
}
long long sap(long long n)
{
    long long i,v,u,flow=0,aug=inf;
    long long flag;
    for (i=1;i<=n;i++)
    {   gap[i]=dis[i]=0;       cur[i]=head[i];    }
    gap[0]=n; //gap[s]=n;
    u=pre[s]=s;
	while (dis[s]<n)
	{   flag=0;
        for (long long j=cur[u];j!=-1;j=e[j].next)
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
        long long mindis=n;
        for (long long j=head[u];j!=-1;j=e[j].next)
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
long long ue[M],ve[M];
int main()
{
	char ch;
	freopen("1.in","r",stdin);
	while (scanf("%lld%lld",&n,&m)!=-1)
	{
		if(m==0)
		{
			if(n!=1) printf("0\n");
			else printf("1\n");
			continue;
		}
		for(long long i=0;i<m;i++)
		{
			scanf(" (%lld,%lld)",&ue[i],&ve[i]);
			ue[i]++; ve[i]++;
		}
		s=n+1;
		long long sum=inf*2;
		for(long long i=2;i<=n;i++)
		{
			cnt=0;
			memset(head,-1,sizeof(head));
			t=i;
			for(long long j=1;j<=n;j++)
				addedge(j,j+n,1);
			for(long long j=0;j<m;j++)
			{
				addedge(ue[j]+n,ve[j],inf);
				addedge(ve[j]+n,ue[j],inf);
			}
			ans=sap(2*n);
			sum=sum>ans?ans:sum;
		}
		if(sum>=inf)printf("%lld\n",n);
		else printf("%lld\n",sum);
	}
	return 0;
}