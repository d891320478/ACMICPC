#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 100010
#define M 10010
int n,m;
int a[N],c[N];
int b[N],l[N],vis[N],step;
int head[N],next[N*2],e[N*2],cnt;
void addedge(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
void dfs(int s)
{
	vis[s]=1;
	l[s]=INF;
	for(int i=head[s];i!=-1;i=next[i])
		if(! vis[e[i]])
		{
			dfs(e[i]);
			l[s]=min(l[s],b[e[i]]);
		}
	if(l[s]==INF) l[s]=0;
	b[s]=++step;
}
int lowbit(int x)
{
	return x & (-x);
}
int sum(int x)
{
	int ans=0;
	while (x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
void update(int x,int val)
{
	while (x<=n)
	{
		c[x]+=val;
		x+=lowbit(x);
	}
}
int main()
{
	while(scanf("%d",&n)!=-1)
	{
		cnt=step=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		dfs(1);
		for(int i=1;i<=n;i++)
		{
			a[b[i]]=1;
			update(b[i],1);
		}
		scanf("%d",&m);
		while (m--)
		{
			char ch;
			int y;
			scanf(" %c %d",&ch,&y);
			if(ch=='Q')
			{
				printf("%d\n",sum(b[y])-sum(l[y]-1));
			}
			else
			{
				if(a[b[y]])
				{
					a[b[y]]=0;
					update(b[y],-1);
				}
				else
				{
					a[b[y]]=1;
					update(b[y],1);
				}
			}
		}
	}
	return 0;
}