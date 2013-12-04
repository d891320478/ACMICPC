#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
#define N 50010
#define M 150010
int head[N],next[M],e[M],l[M];
int n,m,top;
int spfa(int s,int n)
{
	int d[N];
	bool vis[N];
	queue<int>q;
	for(int i=0;i<=n;i++)
		d[i]=-1,vis[i]=0;
	d[s]=0;
	q.push(s);
	vis[s]=1;
	while(! q.empty())
	{
		int now=q.front();
		q.pop();
		vis[now]=0;
		for(int i=head[now];i!=-1;i=next[i])
			if(d[e[i]]<d[now]+l[i])
			{
				d[e[i]]=d[now]+l[i];
				if(! vis[e[i]])
				{
					vis[e[i]]=1;
					q.push(e[i]);
				}
			}
	}
	return d[n];
}
int main ()
{
	while(scanf("%d",&m)!=-1)
	{
		n=top=-1;
		memset(head,-1,sizeof(head));
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if(u>v)swap(u,v);
			v++;
			top++;
			next[top]=head[u];
			head[u]=top;
			e[top]=v;
			l[top]=w;
			n=n>v?n:v;
		}
		for(int i=0;i<n;i++)
		{
			top++;
			next[top]=head[i];
			head[i]=top;
			e[top]=i+1;
			l[top]=0;
			top++;
			next[top]=head[i+1];
			head[i+1]=top;
			e[top]=i;
			l[top]=-1;
		}
		printf("%d\n",spfa(0,n));
	}
	return 0;
}