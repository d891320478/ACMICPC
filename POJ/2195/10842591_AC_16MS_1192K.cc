#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;
#define N 555
#define M 55555
#define INF 1<<30
struct edge
{
	int c,w,v,next;
}e[M];
int head[N],cnt;
int n,m,s,t,ans,flow;
int vis[N],d[N];
void addedge(int u,int v,int w,int c)
{
	e[cnt].next=head[u]; e[cnt].v=v; e[cnt].w=w; e[cnt].c=c; head[u]=cnt++;
	e[cnt].next=head[v]; e[cnt].v=u; e[cnt].w=0; e[cnt].c=-c; head[v]=cnt++;
}
int aug(int u,int f)
{
	if(u==t)
	{
		ans+=flow*f;
		return f;
	}
	vis[u]=1;
	int tmp=f;
	for(int i=head[u];i!=-1;i=e[i].next)
	if(e[i].w && ! e[i].c && ! vis[e[i].v])
	{
		int delta=aug(e[i].v,tmp<e[i].w?tmp:e[i].w);
		e[i].w-=delta;
		e[i^1].w+=delta;
		tmp-=delta;
		if(! tmp)return f;
	}
	return f-tmp;
}
bool modlabel(int n)
{
	for(int i=0;i<=n;i++) d[i]=INF;
	d[t]=0;
	deque<int> q;
	q.push_back(t);
	while(! q.empty())
	{
		int u=q.front();
		q.pop_front();
		for(int i=head[u];i!=-1;i=e[i].next)
			if(e[i^1].w && d[u]-e[i].c<d[e[i].v])
			{
				d[e[i].v]=d[u]-e[i].c;
				d[e[i].v]<=d[q.empty()?s:q.front()]?q.push_front(e[i].v):q.push_back(e[i].v);
			}
	}
	for(int u=1;u<=n;u++)
	for(int i=head[u];i!=-1;i=e[i].next)
		e[i].c+=d[e[i].v]-d[u];
	flow+=d[s];
	return d[s]<INF;
}
void costflow(int n)
{
	while (modlabel(n))
	{
		do{
			memset(vis,0,sizeof(vis));
		}while(aug(s,INF));
	}
}
int nt, mt;
struct point
{
    int x, y;
}p[N], h[N];
int dis[N][N];
char zz[N][N];
int main()
{
   while(scanf("%d%d", &mt, &nt) != EOF)
    {
        if(mt == 0 && nt == 0) break;
        for(int i = 0; i < mt; i++)
            scanf("%s", zz[i]);
        int hcnt = 0, pcnt = 0;
        for(int i = 0; i < mt; i++)
            for(int j = 0; j < nt; j++)
            {
                if(zz[i][j] == 'H')
                {
                    hcnt++;
                    h[hcnt].x = i;
                    h[hcnt].y = j;
                }
                else if(zz[i][j] == 'm')
                {
                    pcnt++;
                    p[pcnt].x = i;
                    p[pcnt].y = j;
                }
            }
        for(int i = 1; i <= pcnt; i++)
            for(int j = 1; j <= hcnt; j++)
                dis[i][j] = abs(p[i].x - h[j].x) + abs(p[i].y - h[j].y);
        memset(head, -1, sizeof(head));
    	cnt=ans=flow=0;
        t= n = hcnt + pcnt + 2;
        s = hcnt + pcnt + 1;
        for(int i = 1; i <= pcnt; i++)
            for(int j = 1; j <= hcnt; j++)
                addedge(i, j + pcnt, 1, dis[i][j]);
        for(int i = 1; i <= pcnt; i++)
            addedge(s, i, 1, 0);
        for(int i = 1; i <= hcnt; i++)
            addedge(i + pcnt, t, 1, 0);
        costflow(n);
        printf("%d\n", ans);
    }
    return 0;
}