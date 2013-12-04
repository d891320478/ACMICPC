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
#define N 500010
#define M 1000010
map<string,int> q;
int head[N],next[M],e[M],cnt;
int poi,sum,into[N],vis[N];
char s1[50],s2[50];
int trie[N][30],lt,end[N],root;
int newnode(){ int nw=lt; lt++; return nw; }
void init()
{ memset(trie,0,sizeof(trie)); memset(end,0,sizeof(end)); lt=poi=0; root=newnode();}
int insert(char *buf)
{	int now=root,l=strlen(buf);
	for(int i=0;i<l;i++)
	{		if(! trie[now][buf[i]-'0']) trie[now][buf[i]-'0']=newnode();
			now=trie[now][buf[i]-'0'];
	}
	if(! end[now])end[now]=++poi;
	return end[now];
}
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
	init();
	while (scanf("%s%s",s1,s2)!=-1)
	{
		int u=insert(s1),v=insert(s2);
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