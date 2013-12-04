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
#include<vector>
#include<utility>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
int fastget()
{
	char c; int ans=0; c=getchar();
	int sign=1;
	while (! (c>='0' && c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while (c>='0' && c<='9')
	{
		ans=(ans<<3)+(ans<<1)+c-'0';
		c=getchar();
	}
	return ans*sign;
}
void fastput(int x)
{
	char s[12]; int a=0;
	if(x==0) puts("0");
	else
	{
		if(x<0) putchar('-'),x=-x;
		while (x) { s[a++]=x%10+'0'; x/=10; }
		for(a--;a>=0;a--) putchar(s[a]);
		putchar('\n');
	}
}
#define N 210
#define M 40010
int n,m;
int vis[N],mk[N],ed[N][N];
int h[N],q[N];
int dfs(int u)
{
	for(int i=0;i<n;i++)
	if(ed[u][i])
	if(! vis[i])
	{
		vis[i]=1;
		if(q[i]==-1 || dfs(q[i]))
		{
			q[i]=u;
			h[u]=i;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int tt=fastget();
	while (tt--)
	{
		n=fastget();
		m=fastget();
		for(int i=0;i<n;i++)
			mk[i]=fastget();
		memset(ed,0,sizeof(ed));
		while (m--)
		{
			int u=fastget(),v=fastget();
			if(u!=v)
			if(mk[u]!=mk[v])
				ed[u][v]=ed[v][u]=1;
		}
		int val=0;
		memset(q,-1,sizeof(q));
		memset(h,-1,sizeof(h));
		for(int i=0;i<n;i++)
		if(mk[i]==0)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) val++;
			//printf("i = %d val = %d\n",i,val);
		}
		memset(vis,0,sizeof(vis));
		printf("%d",val);
		for(int i=0;i<n;i++)
		if(! vis[i])
		if(mk[i]==0 && h[i]!=-1 || mk[i]==1 && q[i]!=-1)
		{
			printf(" %d",i);
			if(mk[i]==0) vis[i]=vis[h[i]]=1;
			else vis[i]=vis[q[i]]=1;
		}
		printf("\n");
	}
	return 0;
}