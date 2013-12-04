#include<stdio.h>
#include<string.h>
const int N=200;
const int M=40000;
const int MAXM=1010;
const int inf=1<<30;
struct Edge{
    int v,next,w;
}e[M];
int head[N],cnt;
int n,m,ans;
int g[N][N],peo[MAXM],a[MAXM];
int s,t;
int pre[N],cur[N],dis[N],gap[N];
void addedge(int u,int v,int w){
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt++;
    e[cnt].v=u;
    e[cnt].w=0;
    e[cnt].next=head[v];
    head[v]=cnt++;
}
int sap(){
    int i,v,u,flow=0,aug=inf;
    int flag;
    for (i=1;i<=n;i++) {
        gap[i]=dis[i]=0;
        cur[i]=head[i];
    }
    gap[0]=n; //gap[s]=n;  点的个数 
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
		printf("%d\n",sap());
	}
	return 0;
}