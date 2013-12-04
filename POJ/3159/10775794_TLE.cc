#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 30010
#define M 150010
int head[N],cnt,vis[N],d[N];
struct edge
{
	int v,next,w;
}e[M];
int n,m;
//queue<int> q;
int q[N*500],open=0,tail=0;
void addedge(int u,int v,int w)
{
	e[cnt].next=head[u];
	e[cnt].v=v;
	e[cnt].w=w;
	head[u]=cnt++;
}
int main ()
{
	scanf("%d%d",&n,&m);
	cnt=0;
	memset(head,-1,sizeof(head));
	memset(d,-1,sizeof(d));
	while (m--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(w<0)continue;
		addedge(u,v,w);
	}
	//q.push(1);
	q[0]=1;
	vis[1]=1;
	d[1]=0;
	//while (! q.empty())
	while (open<=tail)
	{
		//int now=q.front();
		//q.pop();
		int now=q[open++];
		vis[now]=0;
		for(int i=head[now];i!=-1;i=e[i].next)
		{
			int v=e[i].v;
			if(d[v]==-1 || d[v]>d[now]+e[i].w)
			{
				d[v]=d[now]+e[i].w;
				if(! vis[v])
				{
					vis[v]=1;
					//q.push(v);
					q[++tail]=v;
				}
			}
		}
	}
	printf("%d\n",d[n]);
	
	return 0;
}