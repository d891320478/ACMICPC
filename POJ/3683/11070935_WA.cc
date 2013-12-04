//POJ 3683
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
#define M 4000010
int n,m;
int head[N],next[M],e[M],cnt;
int nhead[N],nnext[M],ne[M],ncnt;
int shead[N],snext[M],se[M],scnt;
int dfn[N],low[N],step,point,ins[N];
stack<int> st;
int into[N],color[N],color2[N];
int tl[N][2],tr[N][2],sp[N];
int ts[N],tt[N];
void addedge(int *head,int *next,int *e,int &cnt,int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
void tarjan(int u)
{
	int i,j,v;
	dfn[u]=low[u]=++step;
	st.push(u);
	ins[u]=1;
	for(i=head[u];i!=-1;i=next[i])
	{
		v=e[i];
		if(! dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else
		if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		do{
			j=st.top();
			st.pop();
			color[j]=point;
			ins[j]=0;
		} while (j!=u);
		point++;
	}
}
bool twosat(int n)
{
	for(int i=0;i+1<n;i+=2)
		if(color[i]==color[i+1]) return 0;
	return 1;
}
void COLOR(int s)
{
	color2[s]=1;
	for(int i=nhead[s];i!=-1;i=nnext[i])
		if(color2[ne[i]]==-1) COLOR(ne[i]);
}
void findans(int n)
{
	memset(into,0,sizeof(into));
	memset(color2,-1,sizeof(color2));
	memset(shead,-1,sizeof(shead));
	scnt=0;
	for(int i=0;i<n;i++)
		addedge(shead,snext,se,scnt,color[i],i);
	ncnt=0;
	memset(nhead,-1,sizeof(nhead));
	for(int i=0;i<n;i++)
	for(int j=head[i];j!=-1;j=next[j])
		if(color[i]!=color[e[j]])
		{
			addedge(nhead,nnext,ne,ncnt,color[e[j]],color[i]);
			into[color[i]]++;
		}
	queue<int> Q;
	for(int i=0;i<point;i++)
		if(into[i]==0) Q.push(i);
	while (! Q.empty())
	{
		int x=Q.front();
		Q.pop();
		if(color2[x]!=-1) continue;
		color2[x]=0;
		for(int i=nhead[x];i!=-1;i=nnext[i])
		{
			into[ne[i]]--;
			if(into[ne[i]]==0) Q.push(ne[i]);
		}
		for(int i=shead[x];i!=-1;i=snext[i])
			if(color2[color[se[i]^1]]==-1) COLOR(color[se[i]^1]);
	}
	memset(color,0,sizeof(color));
	for(int i=0;i<point;i++)
		if(color2[i]==1)
		for(int j=shead[i];j!=-1;j=snext[j]) color[se[j]]=1;
	for(int i=0;i<n;i++)
		if(color[i]==0)
		{
			if(i%2==0)
			{
				printf("%02d:%02d ",tl[i/2][0],tl[i/2][1]);
				printf("%02d:%02d\n",(ts[i/2]+sp[i/2])/60,(ts[i/2]+sp[i/2])%60);
			}
			else
			{
				printf("%02d:%02d",(tt[i/2]-sp[i/2])/60,(tt[i/2]-sp[i/2])%60);
				printf(" %02d:%02d\n",tr[i/2][0],tr[i/2][1]);
			}
		}
}
int main ()
{
	while(scanf("%d",&n)!=-1)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d:%d %d:%d %d",&tl[i][0],&tl[i][1],&tr[i][0],&tr[i][1],&sp[i]);
			ts[i]=tl[i][0]*60+tl[i][1];
			tt[i]=tr[i][0]*60+tr[i][1];
		}
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j)
			{
				if(ts[i]<=ts[j] && ts[i]+sp[i]>ts[j] || ts[i]<ts[j]+sp[j] && ts[i]+sp[i]>=ts[j]+sp[j])
				{
					addedge(head,next,e,cnt,i*2,j*2+1);
					//printf("%d %d\n",i*2,j*2+1);
				}
				if(ts[i]<tt[j] && ts[i]+sp[i]>=tt[j] || ts[i]<=tt[j]-sp[j] && ts[i]+sp[i]>tt[j]-sp[j])
				{
					addedge(head,next,e,cnt,i*2,j*2);
					//printf("%d %d\n",i*2,j*2);
				}
				if(tt[i]-sp[i]<=ts[j] && tt[i]>ts[j] || tt[i]-sp[i]<ts[j]+sp[j] && tt[i]>=ts[j]+sp[j])
				{
					addedge(head,next,e,cnt,i*2+1,j*2+1);
					//printf("%d %d\n",i*2+1,j*2+1);
				}
				if(tt[i]-sp[i]<tt[j] && tt[i]>=tt[j] || tt[i]-sp[i]<=tt[j]-sp[j] && tt[i]>tt[j]-sp[j])
				{
					addedge(head,next,e,cnt,i*2+1,j*2);
					//printf("%d %d\n",i*2+1,j*2);
				}
			}
		point=step=0;
		memset(dfn,0,sizeof(dfn));
		for(int i=0;i<n*2;i++)
			if(! dfn[i]) tarjan(i);
		if(! twosat(n*2)) printf("NO\n");
		else
		{
			printf("YES\n");
			findans(2*n);
		}
	}
	
	return 0;
}