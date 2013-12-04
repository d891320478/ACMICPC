#include<stdio.h>

#include<string.h>
#include <algorithm>
using namespace std;

const int N=200;

const int M=40000;

const int MAXM=1010;

const int inf=1<<30;

struct Edge
{

    int v,next,w;

}e[M];

int head[N],cnt;

int n,m,ans;

int s,t;

int pre[N],cur[N],dis[N],gap[N];

void addedge(int u,int v,int w)
{

    e[cnt].v=v;    e[cnt].w=w;    e[cnt].next=head[u];

    head[u]=cnt++;

    e[cnt].v=u;    e[cnt].w=0;    e[cnt].next=head[v];

    head[v]=cnt++;

}

int sap(int n)
{

    int i,v,u,flow=0,aug=inf;

    int flag;

    for (i=1;i<=n;i++)
    {

        gap[i]=dis[i]=0;

        cur[i]=head[i];

    }

    gap[0]=n; //gap[s]=n;

    u=pre[s]=s;

    while (dis[s]<n){

        flag=0;

        for (int j=cur[u];j!=-1;j=e[j].next){

            v=e[j].v;

            if (e[j].w>0&&dis[u]==dis[v]+1){

                flag=1;

                if (e[j].w<aug) aug=e[j].w;

                pre[v]=u;

                u=v;

                if (u==t){

                    flow+=aug;

                    while (u!=s){

                        u=pre[u];

                        e[cur[u]].w-=aug;

                        e[cur[u]^1].w+=aug;

                    }

                    aug=inf;

                }

                break;

            }

            cur[u]=e[j].next;

        }

        if (flag) continue;

        int mindis=n;

        for (int j=head[u];j!=-1;j=e[j].next){

            v=e[j].v;

            if (e[j].w>0&&mindis>dis[v]){

                mindis=dis[v];

                cur[u]=j;

            }

        }

        if (--gap[dis[u]]==0) break;

        dis[u]=mindis+1;

        ++gap[dis[u]];

        u=pre[u];

    }

    return flow;

}

int a[N],b[N],g[N][N],l[M],ll;
int lft,rht,mid,su,ma;
struct ee
{
	int u,v,w;
}ee[M];
int main()
{
    int i,j;
    while(scanf("%d",&n) && n)
    {
		s=n+1,t=n+2;
		ma=su=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			su+=a[i];
		}
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);
		memset(g,-1,sizeof(g));
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&ee[i].u,&ee[i].v,&ee[i].w);
			l[i]=ee[i].w;
		}
		sort(l,l+m);
		ll=0;
		for(i=1;i<m;i++)
			if(l[i]!=l[i-1])l[++ll]=l[i];
		lft=0; rht=ll;
		int ans=-1;
		while(lft<=rht)
		{
			cnt=0;
    		memset(head,-1,sizeof(head));
			mid=(lft+rht)>>1;
			for(i=1;i<=n;i++)
			{
				if(a[i]>0)addedge(s,i,a[i]);
				if(b[i]>0)addedge(i,t,b[i]);
			}
			for(i=0;i<m;i++)
			if(ee[i].w<=l[mid])
			{
				addedge(ee[i].u,ee[i].v,inf);
				addedge(ee[i].v,ee[i].u,inf);
			}
			if(sap(n+2)>=su)rht=mid-1,ans=l[mid];
			else lft=mid+1;
		}
		if(ans==-1) printf("No Solution\n");
		else printf("%d\n",ans);
	}
	return 0;
}