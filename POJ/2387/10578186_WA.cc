#include<string.h>
#include<queue>
#include<stdio.h>
#define MAXE 40001
#define MAXV 10002
using namespace std;
const int INF=1600000000;
typedef pair<int,int> pii;
int t,m,n,V,E,pos=0,head[MAXV];
int ans,d[MAXV];
bool cannot=0;
struct Edge
{
	int w,next,v;
}node[MAXE*2];
void add(int u,int v,int w)
{
	if(u==v) return;
	node[pos].v=v;	node[pos].w=w;	node[pos].next=head[u];
	head[u]=pos++;
}
void dijkstra(int s)
{
	int i;
	for(i=0;i<=V;i++)  d[i]=INF; d[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	bool done[MAXV];
	memset(done,0,sizeof(done));
	q.push(make_pair(d[s],s));
	while(! q.empty())
	{
		pii u=q.top();q.pop();
		int x=u.second;
		if(done[x]) continue;
		done[x]=true;
		for(i=head[x];i!=-1;i=node[i].next)
			if(d[node[i].v]>d[x]+node[i].w)
			{
				d[node[i].v]=d[x]+node[i].w;
				q.push(make_pair(d[node[i].v],node[i].v));
			}
	}
}
int main()
{
	int u,v,w,s,t,ans=0;
	while(scanf("%d%d",&E,&V)!=-1)
	{
		pos=1;
		memset(head,-1,sizeof(head));
		for(int i=0;i<E;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			add(u,v,w); add(v,u,w);
		}
		dijkstra(0);
		printf("%d\n",d[E-1]);
	}
	return 0;
}