#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define PI acos(-1)
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 2010
#define M 1000010
int n,m;
int head[N],cnt,e[M],next[M];
int point,dfn[N],color[N],low[N],step,ins[N];
stack<int> st;
void addedge(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
void tarjan(int u)
{
	dfn[u]=low[u]=++step;
	ins[u]=1;
	st.push(u);
	for(int i=head[u];i!=-1;i=next[i])
		if(! dfn[e[i]])
		{
			tarjan(e[i]);
			low[u]=min(low[u],low[e[i]]);
		}else if(ins[e[i]])
			low[u]=min(low[u],dfn[e[i]]);
	if(dfn[u]==low[u])
	{
		point++;
		int j;
		do{
			j=st.top();
			st.pop();
			ins[j]=0;
			color[j]=point;
		} while (j!=u);
	}
}
int twosat()
{
	for(int i=0;i<2*n;i+=2)
		if(color[i]==color[i+1])return 0;
	return 1;
}
int main ()
{
	while (scanf("%d%d",&n,&m)!=-1)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			char op[5];
			int u,v,w;
			scanf("%d%d%d %s",&u,&v,&w,op);
			if(strcmp(op,"AND")==0)
			{
				if(w==1)
				{
					addedge(u*2,u*2+1);
					addedge(v*2,v*2+1);
					addedge(u*2+1,v*2+1);
					addedge(v*2+1,u*2+1);
				}else
				{
					addedge(u*2+1,v*2);
					addedge(v*2+1,u*2);
				}
			}else if(strcmp(op,"OR")==0)
			{
				if(w==1)
				{
					addedge(u*2,v*2+1);
					addedge(v*2,u*2+1);
				}else
				{
					addedge(u*2+1,u*2);
					addedge(v*2+1,v*2);
					addedge(u*2,v*2);
					addedge(v*2,u*2);
				}
			}else if(strcmp(op,"XOR")==0)
			{
				if(w==1)
				{
					addedge(u*2,v*2+1);
					addedge(v*2+1,u*2);
					addedge(v*2,u*2+1);
					addedge(u*2+1,v*2);
				}else
				{
					addedge(u*2+1,u*2+1);
					addedge(v*2+1,v*2+1);
					addedge(u*2,v*2);
					addedge(v*2,u*2);
				}
			}
		}
		memset(dfn,0,sizeof(dfn));
		memset(ins,0,sizeof(ins));
		step=point=0;
		for(int i=0;i<2*n;i++)
			if(! dfn[i]) tarjan(i);
		if(twosat()) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}