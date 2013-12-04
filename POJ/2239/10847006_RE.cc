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
#define ABS(x) (x)>=0?(x):-(x)
#define N 10010
#define M 10010
int head[N],e[M],next[M],cnt,n;
int h[N],q[N],u[N];
void addedge(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
int dfs(int i)
{
    for(int j=head[i];j!=-1;j=next[j])
  		if(! u[e[j]])
  		{	u[e[j]]=1;
   			if( q[e[j]]==0 || dfs(q[e[j]]) )
   			{    	q[e[j]]=i;		h[i]=e[j];		return 1;		}
  		}
    return 0;
}
int main ()
{
	int i,j,k;
	while (scanf("%d",&n)!=-1)
	{
		memset(head,-1,sizeof(head));
		cnt=0;
		memset(h,0,sizeof(h));
		memset(q,0,sizeof(q));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			while (k--)
			{
				int u,v;
				scanf("%d%d",&u,&v);
				addedge(i,(u-1)*12+v);
			}
		}
		int va=0;
		for(i=1;i<=n;i++)
		{
			memset(u,0,sizeof(u));
			if(dfs(i)) va++;
		}
		printf("%d\n",va);
	}
	return 0;
}