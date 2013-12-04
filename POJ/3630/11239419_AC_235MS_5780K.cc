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
		int flag=1;
		for(int i=1;i<lt && flag;i++)
			if(end[i])
			for(int j=0;j<10;j++)
				if(trie[i][j])
				{
					flag=0;
					break;
				}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}