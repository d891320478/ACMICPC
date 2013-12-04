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
#define N 1000010
#define M 2000010
int poi;
struct trie
{ int x;	trie *p[27];
  void clear(){	for(int i=0;i<26;i++) p[i]=NULL; x=0;	}
}*root;
int ins(char *buf)
{
	trie *head=root;
	for(int i=0;buf[i];i++)
	{
		if(head->p[buf[i]-'a']==NULL)
		{
			head->p[buf[i]-'a']=(trie*)malloc(sizeof(trie));
			head->p[buf[i]-'a']->clear();
		}
		head=head->p[buf[i]-'a'];
	}
	if(! head->x) head->x=++poi;
	return head->x;
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
	root=(trie*)malloc(sizeof(trie));
	root->clear();
	memset(head,-1,sizeof(head));
	while (scanf("%s %s",s1,s2)!=-1)
	{
		int u=ins(s1),v=ins(s2);
		into[u]++; into[v]++;
		add(u,v); add(v,u);
	}
	if(! poi)
	{printf("Possible\n");return 0;}
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