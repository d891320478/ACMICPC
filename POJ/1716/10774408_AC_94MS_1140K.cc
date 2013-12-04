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
#define M 40000
int cnt,head[N],next[M],e[M],l[M],d[N],vis[N];
int n,a,b,s,min0=10001,max0=-1;
queue<int> q;
void addedge(int u,int v,int w)
{
	next[cnt]=head[u];
	e[cnt]=v;
	l[cnt]=w;
	head[u]=cnt++;
}
int main ()
{
	cnt=0;
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		if(min0>a) min0=a;
		if(max0<b+1) max0=b+1;
		addedge(b+1,a,-2);
	}
	for(int i=0;i<max0;i++)
	{
		addedge(i,i+1,1);
		addedge(i+1,i,0);
	}
	memset(d,0x5f,sizeof(d));
	s=max0;
	vis[s]=1; d[s]=0;
	q.push(s);
	while (! q.empty())
	{
		int x=q.front();
		vis[x]=0;
		q.pop();
		for(int i=head[x];i!=-1;i=next[i])
			if(d[e[i]]>d[x]+l[i])
			{
				d[e[i]]=d[x]+l[i];
				if(! vis[e[i]])
				{
					vis[e[i]]=1;
					q.push(e[i]);
				}
			}
	}
	printf("%d\n",d[max0]-d[min0]);
	
	return 0;
}