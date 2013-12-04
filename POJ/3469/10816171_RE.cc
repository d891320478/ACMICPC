#include<stdio.h>
#include<string.h>
#define N 20010
#define M 400010
#define INF 0x3fffffff
using namespace std;
struct edge{
    int x,w,next;
}e[M];
int cnt,n,dis[N],cur[N]={0},pre[N],gap[N]={0},head[N],ed[N];
void addedge(int x,int y,int w)//静态链表插入
{
    if(head[x]==-1)
        cur[x]=head[x]=cnt;
    else
        e[ed[x]].next=cnt;
    ed[x]=cnt;
    e[cnt].x=y;
    e[cnt].next=-1;
    e[cnt++].w=w;
}
int isap()
{
    int i,flow,now,aug,t;
    bool flag;
    flow=now=dis[n-1]=0;
    gap[0]=gap[2]=1;//预先标号，也可以不用
    dis[0]=2;
    for(i=1;i<n-1;i++)
        dis[i]=1;
    gap[1]=n-2;
    while(dis[0]<n)
    {
        if(now==n-1)
        {
            t=now;
            aug=INF;
            while(t!=0)
            {
                t=pre[t];
                if(aug>e[cur[t]].w)
                    aug=e[cur[t]].w;
            }
            flow+=aug;
            while(now!=0)
            {
                now=pre[now];
                e[cur[now]].w-=aug;
                e[cur[now]^1].w+=aug;
            }
        }
        for(flag=true,i=cur[now];i!=-1;i=e[i].next)//cur[now]保存的是当前弧
            if(e[i].w>0&&dis[now]-1==dis[e[i].x])
            {
                cur[now]=i;//更新当前弧
                flag=false;
                break;
            }
            if(flag)
            {
                gap[dis[now]]--;//gap[i]表示标号为i的点的个数
                if(gap[dis[now]]==0)//GAP优化。如果为0，说明出现了间断
                    return flow;
                for(t=n,i=head[now];i!=-1;i=e[i].next)
                    if(e[i].w>0&&t>dis[e[i].x])
                    {
                        cur[now]=i;//重标号时也更新当前弧
                        t=dis[e[i].x];
                    }
                    dis[now]=t+1;
                    gap[t+1]++;
                    if(now!=0)
                        now=pre[now];
            }
            else
            {
                pre[e[i].x]=now;
                now=e[i].x;
            }
    }
    return flow;
}
int main()
{
    int i,j,m,x,y,w;
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(int)*(n+5));
    n++;
    for(cnt=0,i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        addedge(0,i,x);
        addedge(i,0,0);
        addedge(i,n,y);
        addedge(n,i,0);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        addedge(x,y,w);
        addedge(y,x,w);
    }
    n++;
    printf("%d\n",isap());
    return 0;
}
