#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) ((x)>=0?(x):-(x))
#define N 510
#define M 250010
int head[N],cnt,vis[N];
int e[M],next[M];
int poi,n,m,h[N],q[N];
struct point
{
	int a,b,c,d,tim;
	void init(){scanf("%d%d%d%d",&a,&b,&c,&d);}
}p[N];
void addedge(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
int dfs(int i)
{
    for(int j=head[i];j!=-1;j=next[j])
  		if(! vis[e[j]])
  		{	vis[e[j]]=1;
   			if( q[e[j]]==0 || dfs(q[e[j]]) )
   			{    	q[e[j]]=i;		return 1;		}
  		}
    return 0;
}
int main ()
{
	int tttt,i,j;
	scanf("%d",&tttt);
	while (tttt--)
	{
		scanf("%d",&m);
		cnt=0;
		SET(head,-1);
		SET(p,0);
		for(i=1;i<=m;i++)
		{
			int t1,t2,u,v;
			scanf("%d:%d",&t1,&t2);
			p[i].init();
			p[i].tim=t1*60+t2;
		}
		for(i=1;i<=m;i++)
		for(j=1;j<=m;j++)
		if(i!=j)
		{
			if(p[i].c==p[j].a && p[i].d==p[j].b)
			if(p[i].tim+ABS(p[i].a-p[j].a)+ABS(p[i].b-p[j].b)<p[j].tim) addedge(i,j);
		}
		/*for(i=1;i<=m;i++)
		{
			for(j=head[i];j!=-1;j=next[j])
				printf("%d ",e[j]);
			printf("\n");
		}*/
		int va=0;
		SET(q,0);
		for(i=1;i<=m;i++)
		{
			SET(vis,0);
			if(dfs(i)) va++;
		}
		printf("%d\n",m-va);
	}
	
	return 0;
}