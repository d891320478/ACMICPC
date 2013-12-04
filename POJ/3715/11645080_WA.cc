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
int head[N],next[M],e[M],cnt;
int n,m;
int vis[N],mk[N],ed[N][N];
int h[N],q[N];
void add(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
int dfs(int u)
{
	if(h[u]) return 0;
	for(int i=head[u];i!=-1;i=next[i])
	if(! vis[e[i]])
	if(! h[e[i]])
	{
		vis[e[i]]=1;
		if(q[e[i]]==-1 || dfs(q[e[i]]))
		{
			q[e[i]]=u;
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
		cnt=0;
		memset(head,-1,sizeof(head));
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
			if(! ed[u][v])
			{
				ed[u][v]=ed[v][u]=1;
				if(mk[u]==0) add(u,v);
				else add(v,u);
			}
		}
		int val=0,val0,val1;
		memset(q,-1,sizeof(q));
		memset(h,0,sizeof(h));
		for(int i=0;i<n;i++)
		if(mk[i]==0)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) val++;
		}
		printf("%d",val1=val);
		for(int i=0;val1 && i<n;i++)
		{
			val0=0;
			h[i]=1;
			memset(q,-1,sizeof(q));
			for(int j=0;j<n;j++)
			if(! h[j])
			if(mk[j]==0)
			{
				memset(vis,0,sizeof(vis));
				if(dfs(j)) val0++;
			}
			if(val0<val) printf(" %d",i),val1--;
			h[i]=0;
		}
		printf("\n");
	}
	return 0;
}