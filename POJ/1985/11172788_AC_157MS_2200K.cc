#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 50010
#define M 100010
int n,m;
int head[N],cnt,d[N];
int q[N],start,end;
struct edge
{
	int v,w,next;
}e[M];
void addedge(int u,int v,int w)
{
	e[cnt].v=v; e[cnt].w=w; e[cnt].next=head[u];
	head[u]=cnt++;
}
void bfs(int s)
{
	q[start=end=0]=s;
	memset(d,-1,sizeof(d));
	d[s]=0;
	while (start<=end)
	{
		int u=q[start++];
		for(int i=head[u];i!=-1;i=e[i].next)
		{
			if(d[e[i].v]==-1)
			{
				d[e[i].v]=d[u]+e[i].w;
				q[++end]=e[i].v;
			}
		}
	}
}
int main()
{
	while (scanf("%d%d",&n,&m)!=-1)
	{
		cnt=0;
		memset(d,0,sizeof(d));
		memset(head,-1,sizeof(head));
		while (m--)
		{
			int u,v,w; char ch;
			scanf("%d %d %d %c",&u,&v,&w,&ch);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		bfs(1);
		int mx=-1,j;
		for(int i=1;i<=n;i++)
			if(mx<d[i])
			{
				mx=d[i];
				j=i;
			}
		bfs(j);
		mx=-1;
		for(int i=1;i<=n;i++)
			if(mx<d[i]) mx=d[i];
		printf("%d\n",mx);
	}
	return 0;
}