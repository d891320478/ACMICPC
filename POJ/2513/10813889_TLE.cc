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
#define N 250010
#define M 500010
map<string,int> q;
int head[N],next[M],e[M],cnt;
int poi,sum,into[N],vis[N];
string s1,s2;
void addedge(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
void dfs(int s)
{
	sum++;
	vis[s]=1;
	for(int i=head[s];i!=0;i=next[i])
		if(! vis[e[i]]) dfs(e[i]);
}
int main ()
{
	cnt=0;
	while (cin>>s1>>s2)
	{
		int u,v;
		if(! q[s1])u=q[s1]=++poi;
		else u=q[s1];
		if(! q[s2])v=q[s2]=++poi;
		else v=q[s2];
		into[u]++;
		into[v]++;
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1);
	if(poi==sum) printf("Impossible\n");
	else
	{
		int flag=0;
		sum=0;
		for(int i=1;i<=poi;i++) sum+=into[i]%2;
		if(sum==0 || sum==2)printf("Possible\n");
		else printf("Impossible\n");
	}
	return 0;
}