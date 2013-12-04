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
#include<ctime>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 500010
#define M 1000010
int poi;
int trie[N*2][26],lt,end[N*2],root;	char s[M];
int newnode(){ int nw=lt; lt++; return nw; }
void init()
{ memset(trie,0,sizeof(trie)); memset(end,0,sizeof(end)); lt=0; root=newnode();}
int insert(char *buf)
{	int now=root,l=strlen(buf);
	for(int i=0;i<l;i++)
	{	if(! trie[now][buf[i]-'a']) trie[now][buf[i]-'a']=newnode();
		now=trie[now][buf[i]-'a'];
	}
	if(! end[now]) end[now]=++poi;
	return end[now];
}
int head[N],next[M],e[M],cnt,into[N],sum,vis[N];
char s1[15],s2[15];
void add(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
void dfs(int u)
{
	sum++;
	vis[u]=1;
	for(int i=head[u];i!=-1;i=next[i])
		if(! vis[e[i]]) dfs(e[i]);
}
int main()
{
	cnt=0;
	memset(head,-1,sizeof(head));
	init();
	while (scanf("%s %s",s1,s2)!=-1)
	{
		int u=insert(s1),v=insert(s2);
		into[u]++; into[v]++;
		add(u,v); add(v,u);
	}
	dfs(1);
	if(poi!=sum) printf("Impossible\n");
	else
	{
		sum=0;
		for(int i=1;i<=poi;i++) if(into[i]%2) sum++;
		if(sum==0 || sum==2) printf("Possible\n");
		else printf("Impossible\n");
	}
	return 0;
}