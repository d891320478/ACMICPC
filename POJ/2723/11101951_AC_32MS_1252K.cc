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
#define N 5000
#define M 100000
int n,m,u[M],v[M],a[N];
int head[N],next[M],e[M],cnt;
int l,r,mid;
int dfn[N],low[N],ins[N],color[N],point,step;
stack <int> st;
void addedge(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
void tarjan(int u)
{
	dfn[u]=low[u]=++step;
	st.push(u);
	ins[u]=1;
	for(int i=head[u];i!=-1;i=next[i])
	{
		if(! dfn[e[i]])
		{
			tarjan(e[i]);
			low[u]=min(low[u],low[e[i]]);
		}
		else if(ins[e[i]]) low[u]=min(low[u],dfn[e[i]]);
	}
	if(dfn[u]==low[u])
	{
		int j;
		do{
			j=st.top();
			st.pop();
			ins[j]=0;
			color[j]=point;
		} while (j!=u);
		point++;
	}
}
bool twosat(int n)
{
	for(int i=0;i<n;i+=2)
		if(color[i]==color[i+1]) return 0;
	return 1;
}
int main()
{
	while (scanf("%d%d",&n,&m) && n+m)
	{
		for(int i=1;i<=n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x]=y;
			a[y]=x;
		}
		for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
		l=0,r=m;
		while (l<r)
		{
			mid=(l+r+1)>>1;
			cnt=0;
			memset(head,-1,sizeof(head));
			step=point=0;
			memset(dfn,0,sizeof(dfn));
			for(int i=0;i<2*n;i++)
			{
				addedge(i*2,a[i]*2+1);
				addedge(a[i]*2,i*2+1);
			}
			for(int i=1;i<=mid;i++)
			{
				if(u[i]==v[i]) addedge(u[i]*2+1,u[i]*2);
				else
				{
					addedge(u[i]*2+1,v[i]*2);
					addedge(v[i]*2+1,u[i]*2);
				}
			}
			for(int i=0;i<4*n;i++)
				if(! dfn[i]) tarjan(i);
			if(twosat(n*4)) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}