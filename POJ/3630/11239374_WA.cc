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
#define N 100010
#define M 12
int trie[N][M],lt,end[N],root;
char s[M];
int newnode()
{
	int nw=lt;
	lt++;
	return nw;
}
void init()
{
	memset(trie,0,sizeof(trie));
	memset(end,0,sizeof(end));
	lt=0;
	root=newnode();
}
void insert(char *buf)
{
	int now=root,l=strlen(buf);
	for(int i=0;i<l;i++)
	{
		if(! trie[now][buf[i]-'0'])
			trie[now][buf[i]-'0']=newnode();
		now=trie[now][buf[i]-'0'];
	}
	end[now]=1;
}
int q[N*M][2];
int bfs()
{
	q[0][0]=root; q[0][1]=0;
	int start=0,tail=0;
	while (start<=tail)
	{
		int u=q[start][0];
		for(int i=0;i<10;i++)
			if(trie[u][i])
			{
				if(end[trie[u][i]])
				if(q[start][1])
				return 1;
				q[++tail][0]=trie[u][i];
				q[tail][1]=end[u] || q[start][1];
			}
		start++;
	}
	return 0;
}
int main()
{
	int tt,n;
	scanf("%d",&tt);
	while (tt--)
	{
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			//printf("%s\n",s);
			insert(s);
		}
		if(bfs())printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}