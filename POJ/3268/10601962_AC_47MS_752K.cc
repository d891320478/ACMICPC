#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
#define N 1010
#define M 200010
int head[N],next[M],e[M],l[M],headl[N],nextl[M],el[M],ll[M],d[N],dl[N],ans;
int n,m,x;
void spfa(int s,int *head,int *next,int *e,int *l)
{
	queue<int> q;
	bool vis[N]={0};
	q.push(s);
	vis[s]=1;
	set(d,-1);
	d[s]=0;
	while (! q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x];i!=-1;i=next[i])
			if(d[e[i]]==-1 || d[e[i]]>d[x]+l[i])
			{
				d[e[i]]=d[x]+l[i];
				if(! vis[e[i]])
				{
					vis[e[i]]=1;
					q.push(e[i]);
				}
			}
	}
}
int main ()
{
	scanf("%d%d%d",&n,&m,&x);
	set(head,-1);
	set(headl,-1);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		next[i]=head[u];
		head[u]=i;
		e[i]=v;
		l[i]=w;
		nextl[i]=headl[v];
		headl[v]=i;
		el[i]=u;
		ll[i]=w;
	}
	ans=0;
	spfa(x,head,next,e,l);
	for(int i=1;i<=n;i++)
		dl[i]=d[i];
	spfa(x,headl,nextl,el,ll);
	for(int i=1;i<=n;i++)
		ans=ans>d[i]+dl[i]?ans:d[i]+dl[i];
	printf("%d\n",ans);
	
	return 0;
}
