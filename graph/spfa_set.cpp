#include<cstdio>
#include<cstring>
#include<set>
#include<utility>
using namespace std;
#define N 100010
#define M 400010
int m,n,s,t1,t2;
set<pair<int,int> > Q;
int head[N],cnt;
int d[N],vis[N];
struct edge
{
	int v,w,next;
}e[M];
void addedge(int u,int v,int w)
{
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
void spfa(int s)
{
	memset(d,-1,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[s]=0;
	vis[s]=1;
	Q.clear();
	Q.insert(make_pair(d[s],s));
	while (! Q.empty())
	{
		int u=(*Q.begin()).second,v;
		Q.erase(Q.begin());
		vis[u]=0;
		for(int i=head[u];i!=-1;i=e[i].next)
		if(d[e[i].v]>d[u]+e[i].w || d[e[i].v]==-1)
		{
			v=e[i].v;
			if(! vis[v]) vis[v]=1;
			else Q.erase(make_pair(d[v],v));
			d[v]=d[u]+e[i].w;
			Q.insert(make_pair(d[v],v));
		}
	}
}
